#include <iostream>

using std::cout;

int foo(int a)
{
    static int b = 0;
    ++b;
    return a == 0 ? b : a;
}

int main()
{
    cout << foo(1) << '\n';
    cout << foo(2) << '\n';
    cout << foo(0);

    return 0;
}
