#include <iostream>

int a = -30 * 3 + 21 / 5; //-86
int b = -30 + 3 * 1 / 5;  //-30
int c = 30 / 3 * 21 % 5;  //0
int d = -30 / 3 * 21 % 4; // -2

int main()
{
    std::cout << a << ' ' << b << ' ' << c << ' ' << d;

    return 0;
}
