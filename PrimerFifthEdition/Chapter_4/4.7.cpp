#include <iostream>

unsigned a = 0;
short b = 32767;
char c = 0;

int main()
{
    std::cout << --a << ' ' << ++b << ' ' << --c << std::endl
              << a;

    return 0;
}
