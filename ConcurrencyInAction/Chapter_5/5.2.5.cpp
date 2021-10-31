#include <atomic>
#include <iostream>

int main()
{
    std::atomic<int> a{0b1111};
    auto b = a.fetch_and(0b0011);
    a |= 0b1100; // 内部调用fetch_or()

    std::cout << b << " " << a << std::endl;

    return 0;
}
