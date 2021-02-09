#include <iostream>

using std::cout;

int abs(int a)
{
    return a < 0 ? -a : a;
}

int main()
{
    cout << abs(-5);

    return 0;
}
