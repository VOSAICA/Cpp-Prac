#include <iostream>

int main()
{
    int a = 0;
    int b = 1;
    int *p1 = &a;
    std::cout << *p1 << std::endl;
    p1 = &b;
    std::cout << *p1 << std::endl;
    *p1 = 2;
    std::cout << b << std::endl;

    return 0;
}
