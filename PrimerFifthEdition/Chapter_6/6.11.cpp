#include <iostream>

using std::cout;

void reset(int& a)
{
    a = 0;
}

int main()
{
    int a = 999;
    reset(a);

    cout << a;

    return 0;
}
