#include <iostream>

int a = 12 / 3 * 4 + 5 * 15 + 24 % 4 / 2;       //16 + 75 + 0 = 91
int b = (12 / 3 * 4) + (5 * 15) + (24 % 4 / 2); //16 + 75 + 0 = 91

int main()
{
    std::cout << a << ' ' << b;

    return 0;
}
