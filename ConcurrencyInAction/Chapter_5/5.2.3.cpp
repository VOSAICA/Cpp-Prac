#include <atomic>
#include <iostream>

int main()
{
    std::atomic<bool> b{false};
    auto a{b = false}; // 这里返回的不是b的引用，而是b被赋予的值
    b.store(true);

    bool x = b.load(std::memory_order_acquire);
    std::cout << "b: " << b << std::endl;
    std::cout << "x: " << x << std::endl;
    x = b.exchange(false, std::memory_order_acq_rel); // 返回原始值
    std::cout << "b: " << b << std::endl;
    std::cout << "x: " << x << std::endl << std::endl;

    // 如果b等于expected，b被赋予desired
    // 如果b不等于expected，expected被赋予b
    b = false;
    bool expected = true;
    bool desired = true;
    std::cout << "b.load(): " << b.load() << std::endl;
    std::cout << "expected: " << expected << std::endl;
    std::cout << "desired: " << desired << std::endl;
    while (!b.compare_exchange_weak(expected, desired))
    {
        // 这里b不等于expected，expected被赋予b，返回false
        // 又一次循环，这回导致b被赋予desired
    };
    std::cout << "b.load(): " << b.load() << std::endl;
    std::cout << "expected: " << expected << std::endl;
    std::cout << "desired: " << desired << std::endl << std::endl;

    b = true;
    expected = true;
    desired = false;
    std::cout << "b.load(): " << b.load() << std::endl;
    std::cout << "expected: " << expected << std::endl;
    std::cout << "desired: " << desired << std::endl;
    while (!b.compare_exchange_weak(expected, desired))
    {
    };
    std::cout << "b.load(): " << b.load() << std::endl;
    std::cout << "expected: " << expected << std::endl;
    std::cout << "desired: " << desired << std::endl;

    expected = false;
    while (!b.compare_exchange_weak(expected, desired) && !expected) // 处理伪失败
    {
        // !b.compare_exchange_weak(expected, desired)被打断时有两种可能性

        // 1. b不等于expected，b还没赋予给expected
        // 这种情况下，expected本该为true，但还是false
        // 循环就还会继续

        // 2. b等于expected，但b还没被赋予desired就有指令打断了
        // expected不变，依旧是false
        // 循环就还会继续
    }

    return 0;
}
