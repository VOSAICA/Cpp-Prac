#include <iostream>

using std::cout;

void swap_pointer(int *&a, int *&b)
{
    int *c = a;
    a = b;
    b = c;
}

int main()
{
    int a = 10, b = 12;
    int *c = &a, *d = &b;

    swap_pointer(c, d);
    cout << *c << ' ' << *d;

    return 0;
}
