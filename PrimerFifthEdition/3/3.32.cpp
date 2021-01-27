#include <cstddef>
#include <iostream>
#include <vector>

int main()
{
    int a[10] = {};
    for (size_t i = 0; i < 10; ++i)
        a[i] = i;

    int b[10] = {};
    for (size_t i = 0; i < 10; ++i)
        b[i] = a[i];

    std::vector<int> a1;
    for (int i = 0; i < 10; i++)
        a1.emplace_back(i);

    std::vector<int> b1 = a1;

    for (size_t i = 0; i < 10; ++i)
        std::cout << b[i];
    std::cout << '\n';

    for (auto i : b1)
        std::cout << b1[i];

    return 0;
}
