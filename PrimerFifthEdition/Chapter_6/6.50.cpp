#include <iostream>

using std::cout;

void f();
void f(int);
void f(int, int);
void f(double, double = 3.14);

int main()
{
    f(2.56, 42);   // 二义性
    f(42);         // 2
    f(42, 0);      // 3
    f(2.56, 3.14); // 4

    return 0;
}
