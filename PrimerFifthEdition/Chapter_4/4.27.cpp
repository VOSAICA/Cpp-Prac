#include <iostream>

using std::cout;

int main()
{
    unsigned long ul1 = 3, ul2 = 7;

    cout << (ul1 & ul2) << '\n'; // 0011 & 0111 = 0011
    cout << (ul1 | ul2) << '\n'; // 0011 | 0111 = 0111
    cout << (ul1 && ul2) << '\n';
    cout << (ul1 || ul2);

    return 0;
}
