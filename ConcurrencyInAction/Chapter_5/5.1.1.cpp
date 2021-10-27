#include <iostream>

struct my_data
{
    int i : 3;
    int j : 29;
};

struct S
{
    // will usually occupy 2 bytes:
    // 3 bits: value of b1
    // 2 bits: unused
    // 6 bits: value of b2
    // 2 bits: value of b3
    // 3 bits: unused
    unsigned char b1 : 3, : 2, b2 : 6, b3 : 2;
};

int main()
{
    my_data d;
    d.i = 7;
    // auto p = &d.i; 位域不能取址
    std::cout << sizeof(my_data) << ' ' << d.i << std::endl;
    std::cout << sizeof(S) << std::endl;

    return 0;
}
