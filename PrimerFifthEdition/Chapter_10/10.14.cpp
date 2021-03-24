#include <iostream>

using std::cout;

int main()
{
    auto f = [](int a, int b) { return a + b; };
    cout << f(1, 4);

    return 0;
}
