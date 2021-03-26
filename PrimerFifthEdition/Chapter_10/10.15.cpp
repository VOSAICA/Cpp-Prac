#include <iostream>

using std::cout;

int main()
{
    int a = 2;
    auto sum = [a](int b) { return a + b; };

    cout << sum(8);

    return 0;
}
