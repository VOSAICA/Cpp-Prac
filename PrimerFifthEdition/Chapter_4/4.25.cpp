#include <iostream>

using std::cout;

int main()
{
    int a = 0b01110001;
    cout << a << ' ';        // 113
    cout << (a << 6) << ' '; // 113 * 2 ^ 6

    cout << ('q' << 6); // 113 * 2 ^ 6

    return 0;
}
