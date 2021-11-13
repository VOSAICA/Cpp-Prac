#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <mutex>
#include <shared_mutex>
#include <string>
#include <thread>
#include <utility>
#include <vector>

template <typename Key, typename Value, typename Hash = std::hash<Key>>
class threadsafe_lookup_table
{
private:
    class bucket_type
    {
        friend std::map<Key, Value> threadsafe_lookup_table::get_map() const;

    private:
        using bucket_value = std::pair<Key, Value>;
        using bucket_data = std::list<bucket_value>;
        using bucket_iterator = typename bucket_data::iterator;
        using bucket_const_iterator = typename bucket_data::const_iterator;

        bucket_data data;
        mutable std::shared_mutex m;

        bucket_iterator find_entry_for(const Key& key)
        {
            return std::find_if(data.begin(), data.end(), [&](const bucket_value& item) { return item.first == key; });
        }

        bucket_const_iterator find_entry_for(const Key& key) const
        {
            return std::find_if(data.cbegin(), data.cend(), [&](const bucket_value& item) { return item.first == key; });
        }

    public:
        Value value_for(const Key& key, const Value& default_value) const
        {
            std::shared_lock<std::shared_mutex> lock(m); // 其他shared_lock可以共享锁
            const auto found_entry = find_entry_for(key);
            return (found_entry == data.end()) ? default_value : found_entry->second;
        }

        void add_or_update_mapping(Key const& key, Value const& value)
        {
            std::unique_lock<std::shared_mutex> lock(m);
            const auto found_entry = find_entry_for(key);
            if (found_entry == data.end())
            {
                data.push_back(bucket_value(key, value));
            }
            else
            {
                found_entry->second = value;
            }
        }

        void remove_mapping(const Key& key)
        {
            std::unique_lock<std::shared_mutex> lock(m);
            const auto found_entry = find_entry_for(key);
            if (found_entry != data.end())
            {
                data.erase(found_entry);
            }
        }
    };

    std::vector<std::unique_ptr<bucket_type>> buckets;
    Hash hasher;

    [[nodiscard]] bucket_type& get_bucket(Key const& key) const
    {
        const std::size_t bucket_index = hasher(key) % buckets.size();
        return *buckets[bucket_index];
    }

public:
    using key_type = Key;
    using mapped_type = Value;
    using hash_type = Hash;

    threadsafe_lookup_table(unsigned num_buckets = 19, const Hash& hasher_ = Hash{}) : buckets{num_buckets}, hasher{hasher_}
    {
        for (auto& bucket : buckets)
        {
            bucket.reset(std::make_unique<bucket_type>().release());
        }
    }

    threadsafe_lookup_table(const threadsafe_lookup_table& other) = delete;
    threadsafe_lookup_table& operator=(const threadsafe_lookup_table& other) = delete;

    [[nodiscard]] Value value_for(const Key& key, const Value& default_value = Value{}) const
    {
        return get_bucket(key).value_for(key, default_value);
    }

    void add_or_update_mapping(const Key& key, const Value& value)
    {
        get_bucket(key).add_or_update_mapping(key, value);
    }

    void remove_mapping(const Key& key)
    {
        get_bucket(key).remove_mapping(key);
    }

    [[nodiscard]] std::map<Key, Value> get_map() const
    {
        std::vector<std::unique_lock<std::shared_mutex>> locks;
        for (auto& bucket : buckets)
        {
            locks.push_back(std::unique_lock<std::shared_mutex>{bucket->m});
        }

        std::map<Key, Value> result;
        for (auto& bucket : buckets)
        {
            for (const auto& item : bucket->data)
            {
                result.insert(item);
            }
        }
        return result;
    }
};

int main()
{
    threadsafe_lookup_table<std::string, int> t;
    std::thread t1{[&]()
                   {
                       t.add_or_update_mapping("Slash", 12);
                       t.add_or_update_mapping("Dust", 5);
                       t.remove_mapping("Punch");
                       t.add_or_update_mapping("Kick", 2);
                   }};
    std::thread t2{[&]()
                   {
                       t.add_or_update_mapping("Punch", 3);
                       t.add_or_update_mapping("Dust", 7);
                       t.add_or_update_mapping("Heavy Slash", 5);
                       t.remove_mapping("Kick");
                   }};

    t1.join();
    auto m1 = t.get_map();
    t2.join();
    auto m2 = t.get_map();

    for (const auto& item : m1)
    {
        std::cout << item.first << " " << item.second << std::endl;
    }
    std::cout << std::endl;
    for (const auto& item : m2)
    {
        std::cout << item.first << " " << item.second << std::endl;
    }

    return 0;
}
