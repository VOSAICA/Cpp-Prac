#include <iostream>

int main()
{
    unsigned u1 = 10, u2 = 42;
    std::cout << u2 - u1 << std::endl;
    std::cout << u1 - u2 << std::endl;
    //  00 00 00 0A
    //- 00 00 00 2A
    //= FF FF FF E0
    std::cout << 0xffffffe0 << std::endl;

    int i1 = 10, i2 = 42;
    std::cout << i2 - i1 << std::endl;
    std::cout << i1 - i2 << std::endl;
    std::cout << i1 - u1 << std::endl;
    std::cout << u1 - i1 << std::endl;

    return 0;
}
