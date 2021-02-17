#include <iostream>

int main()
{
    int a = 12;
    float b = 12.0f;
    int* p1 = &a;
    void* p2 = &b;

    if (p1)
        std::cout << "p1: " << *p1 << '\n';
    if (p2)
        std::cout << "p2: " << p2 << '\n';

    return 0;
}
