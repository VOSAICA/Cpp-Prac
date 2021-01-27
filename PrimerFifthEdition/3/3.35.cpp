#include <iostream>
#include <vector>

int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    auto p1 = std::begin(a);
    auto p2 = std::end(a);

    for (auto x : a)
        std::cout << x;
    std::cout << '\n';

    for (p1; p1 != p2; ++p1)
        *p1 = 0;

    for (auto x : a)
        std::cout << x;

    return 0;
}
