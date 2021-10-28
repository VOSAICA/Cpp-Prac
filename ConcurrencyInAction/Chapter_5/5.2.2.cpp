#include <atomic>
#include <iostream>
#include <mutex>

class spinlock_mutex
{
    std::atomic_flag flag{ATOMIC_FLAG_INIT};

public:
    spinlock_mutex() = default;

    void lock()
    {
        while (flag.test_and_set(std::memory_order_acquire)) // 一直循环，直到获取到锁，旧值为false，新值为true
        {
        }
    }

    void unlock()
    {
        flag.clear(std::memory_order_release); // 新值为false
    }
};

int main()
{
    std::atomic_flag f = ATOMIC_FLAG_INIT;
    f.clear(std::memory_order_release);
    bool x = f.test_and_set();

    spinlock_mutex sm;

    {
        std::lock_guard<spinlock_mutex> lk(sm);
        std::cout << "上锁了" << std::endl;
    }
    std::cout << "已经解锁" << std::endl;

    std::lock_guard<spinlock_mutex> lk(sm);
    std::lock_guard<spinlock_mutex> lk2(sm); // 死锁

    return 0;
}
