#include <iostream>
#include <memory>
#include <mutex>
#include <thread>
#include <type_traits>

template <typename T>
class threadsafe_list
{
private:
    struct node
    {
        node() : next(nullptr)
        {
        }

        node(const T& value) : data(std::make_shared<T>(value))
        {
        }

        std::mutex m;
        std::shared_ptr<T> data;
        std::unique_ptr<node> next;
    };

    node head;

public:
    threadsafe_list() = default;
    threadsafe_list(const threadsafe_list& other) = delete;
    threadsafe_list& operator=(const threadsafe_list& other) = delete;
    ~threadsafe_list()
    {
        remove_if([](const node&) { return true; });
    }

    void push_front(const T& value)
    {
        std::unique_ptr<node> new_node{std::make_unique<node>(value)};
        std::lock_guard<std::mutex> lk(head.m);
        new_node->next = std::move(head.next);
        head.next = std::move(new_node);
    }

    template <typename Function>
    void for_each(Function f)
    {
        node* current = &head;
        std::unique_lock<std::mutex> lk(head.m);
        while (node* const next = current->next.get())
        {
            std::unique_lock<std::mutex> next_lk(next->m);
            lk.unlock();
            f(*next->data);
            current = next;
            lk = std::move(next_lk);
        }
    }

    template <typename Predicate>
    std::shared_ptr<T> find_first_if(Predicate p)
    {
        node* current = &head;
        std::unique_lock<std::mutex> lk(head.m);
        while (node* const next = current->next.get())
        {
            std::unique_lock<std::mutex> next_lk(next->m);
            lk.unlock();
            if (p(*next->data))
            {
                return next->data;
            }
            current = next;
            lk = std::move(next_lk);
        }
        return std::shared_ptr<T>{nullptr};
    }

    template <typename Predicate>
    void remove_if(Predicate p)
    {
        node* current = &head;
        std::unique_lock<std::mutex> lk(head.m);
        while (node* const next = current->next.get())
        {
            std::unique_lock<std::mutex> next_lk(next->m);
            if (p(*next->data))
            {
                std::unique_ptr<node> old_next{std::move(current->next)};
                current->next = std::move(next->next);
                next_lk.unlock();
            }
            else
            {
                lk.unlock();
                current = next;
                lk = std::move(next_lk);
            }
        }
    }
};

int main()
{
    threadsafe_list<int> l;

    auto t1 = std::thread(
        [&]()
        {
            for (int i = 0; i < 10; ++i)
            {
                l.push_front(i);
            }
        });
    auto t2 = std::thread(
        [&]()
        {
            for (int i = 100; i < 110; ++i)
            {
                l.push_front(i);
            }
        });
    t1.join();
    t2.join();

    l.find_first_if([](int i) { return i == 3; });
    l.remove_if([](int i) { return i == 2; });
    l.for_each([](int i) { std::cout << i << std::endl; });

    return 0;
}
