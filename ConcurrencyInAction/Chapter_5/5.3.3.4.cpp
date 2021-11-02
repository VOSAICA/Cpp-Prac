#include <array>
#include <atomic>
#include <cassert>
#include <iostream>
#include <thread>

std::array<std::atomic<int>, 3> data;
std::atomic<int> sync(0);

void thread_1()
{
    data.at(0).store(42, std::memory_order_relaxed);
    data.at(1).store(97, std::memory_order_relaxed);
    data.at(2).store(17, std::memory_order_relaxed);
    sync.store(1, std::memory_order_release);
}

void thread_2()
{
    int expected = 1;
    while (!sync.compare_exchange_strong(expected, 2, std::memory_order_acq_rel))
    {
        expected = 1;
    }
}

void thread_3()
{
    while (sync.load(std::memory_order_acquire) < 2)
    {
    }
    assert(data.at(0).load(std::memory_order_relaxed) == 42);
    assert(data.at(1).load(std::memory_order_relaxed) == 97);
    assert(data.at(2).load(std::memory_order_relaxed) == 17);
}

int main()
{
    std::thread t1(thread_1);
    std::thread t2(thread_2);
    std::thread t3(thread_3);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
