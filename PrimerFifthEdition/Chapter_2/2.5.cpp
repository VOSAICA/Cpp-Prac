#include <iostream>

int main()
{
    std::cout << 'a' << std::endl;  // char
    std::cout << L'a' << std::endl; // wchar_t
    std::cout << "a" << std::endl;  // const char [2]
    std::cout << L"a" << std::endl; // const wchar_t [2]

    std::cout << 10 << std::endl;   // int
    std::cout << 10u << std::endl;  // unsigned int
    std::cout << 10L << std::endl;  // long
    std::cout << 10uL << std::endl; // unsigned long
    std::cout << 012 << std::endl;  // int (Octodecimal)
    std::cout << 0xc << std::endl;  // int (Hexadecimal)

    std::cout << 3.14 << std::endl;  // double
    std::cout << 3.14f << std::endl; // float
    std::cout << 3.14L << std::endl; // long double

    std::cout << 10 << std::endl;    // int
    std::cout << 10u << std::endl;   // unsigned int
    std::cout << 10. << std::endl;   // double
    std::cout << 10e-2 << std::endl; // double (10 * 10 ^ -2)

    return 0;
}
