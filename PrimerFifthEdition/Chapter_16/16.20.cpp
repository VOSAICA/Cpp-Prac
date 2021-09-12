#include <iostream>
#include <vector>

template <typename T>
void printAll(const T& container)
{
    for (const auto& i : container)
    {
        std::cout << i << ' ';
    }
}

int main()
{
    std::vector<int> a = {0, 1, 2, 3, 4, 5, 6, 7};
    printAll(a);

    return 0;
}
