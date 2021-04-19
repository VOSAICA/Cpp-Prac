#include <iostream>
#include <memory>
#include <string>

using std::allocator;
using std::cin;
using std::string;

int main()
{
    size_t n = 5;
    allocator<string> stringAllocator;
    auto p = stringAllocator.allocate(n);
    string s;

    auto start = p;
    while (p != start + n && cin >> s) // 这个顺序影响的
    {
        stringAllocator.construct(p++, s);
    }

    while (p != start)
    {
        std::cout << *--p;
        stringAllocator.destroy(p);
    }
    stringAllocator.deallocate(start, n);

    return 0;
}
