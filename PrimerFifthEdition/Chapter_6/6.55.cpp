#include <iostream>
#include <vector>

using std::vector;

int plus(int a, int b) { return a + b; }
int minus(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { return a / b; }

using calculateFunc = decltype(plus);

int main()
{
    vector<calculateFunc*> vec;

    vec.emplace_back(plus);
    vec.emplace_back(minus);
    vec.emplace_back(multiply);
    vec.emplace_back(divide);

    return 0;
}
