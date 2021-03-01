#include <iostream>

struct X
{
    X(int i, int j) : base(i), rem(base % j)
    {
    }
    int base, rem; // Base在rem之前被初始化，可以工作
};

int main()
{
    X a(5, 2);
    std::cout << a.rem << ' ' << a.base;

    return 0;
}
