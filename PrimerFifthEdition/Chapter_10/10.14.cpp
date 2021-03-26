#include <iostream>

using std::cout;

int main()
{
    auto sum = [](int a, int b) -> int { return a + b; };
    cout << sum(1, 4);

    return 0;
}
