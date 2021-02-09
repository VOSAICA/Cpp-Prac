#include <iostream>

using std::cout;

int add(int a, int b) { return a + b; } //a, b是形参

int main()
{
    cout << add(1, 1); //1, 1是实参
    return 0;
}
