#include <iostream>
#include <map>
#include <mutex>
#include <shared_mutex>
#include <string>
#include <vector>

using dns_entry = std::string;

class dns_cache
{
    std::map<std::string, dns_entry> entries;
    mutable std::shared_mutex entry_mutex;

public:
    dns_entry find_entry(const std::string& domain) const
    {
        std::shared_lock<std::shared_mutex> lk(entry_mutex); // 尝试独占锁的线程会被阻塞，可以跟别的线程分享锁
        const auto it = entries.find(domain);

        return (it == entries.end()) ? dns_entry() : it->second;
    }

    void update_or_add_entry(const std::string& domain, const dns_entry& dns_details)
    {
        std::lock_guard<std::shared_mutex> lk(entry_mutex); // 独占锁
        entries.insert_or_assign(domain, dns_details);
    }
};

void output_domain(const dns_cache& dc)
{
    std::cout << dc.find_entry("www.baidu.com") << '\n';
}

void add_baidu(dns_cache& dc)
{
    dc.update_or_add_entry("www.baidu.com", "487.475.121");
}

int main()
{
    dns_cache dc;

    std::thread t0(add_baidu, std::ref(dc));
    std::thread ta(output_domain, std::ref(dc));
    std::thread tb(output_domain, std::ref(dc));
    std::thread tc(output_domain, std::ref(dc));

    t0.join();
    ta.join();
    tb.join();
    tc.join();

    return 0;
}
