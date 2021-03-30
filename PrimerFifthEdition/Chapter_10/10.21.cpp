#include <iostream>

using std::cout;

int main()
{
    int a = 10;
    auto f = [&a]() {
        while (a != 0)
            --a;
        return a == 0;
    };

    cout << a << '\n';
    f();
    cout << a << '\n';
    f();
    cout << a;

    return 0;
}
