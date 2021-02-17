#include <iostream>

using std::cout;

void f()
{
    cout << 1;
}
void f(int)
{
    cout << 2;
}
void f(int, int)
{
    cout << 3;
};
void f(double, double = 3.14)
{
    cout << 4;
}

int main()
{
    f(2.56, 42);   //二义性
    f(42);         // 2
    f(42, 0);      // 3
    f(2.56, 3.14); // 4

    return 0;
}
