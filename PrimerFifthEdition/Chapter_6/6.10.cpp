#include <iostream>

using std::cout;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a = 0, b = 2;

    cout << a << ' ' << b << '\n';
    swap(&a, &b);
    cout << a << ' ' << b;

    return 0;
}
