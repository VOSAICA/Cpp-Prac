#include <iostream>
#include <stdexcept>

using std::cin;
using std::cout;

int main()
{
    int a, b;
    cin >> a >> b;

    if (b == 0)
        throw std::runtime_error("Divider must not be 0");
    cout << a / b;

    return 0;
}
