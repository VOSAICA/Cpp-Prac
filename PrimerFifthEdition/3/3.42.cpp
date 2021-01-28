#include <iostream>
#include <vector>

int main()
{
    std::vector<int> a;
    int b[5]{5, 4, 3, 2, 1};

    for (auto i : b)
        a.emplace_back(i);

    for (auto i : a)
        std::cout << i;

    return 0;
}
