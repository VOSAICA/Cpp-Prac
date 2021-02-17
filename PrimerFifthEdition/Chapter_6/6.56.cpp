#include <iostream>
#include <vector>

using std::cout;
using std::vector;

int plus(int a, int b)
{
    return a + b;
}
int minus(int a, int b)
{
    return a - b;
}
int multiply(int a, int b)
{
    return a * b;
}
int divide(int a, int b)
{
    return a / b;
}

using calculateFunc = decltype(plus);

int main()
{
    vector<calculateFunc*> vec{plus, minus, multiply, divide};

    for (auto i : vec)
        cout << i(8, 4) << '\n';

    return 0;
}
