#include <iostream>
#include <vector>

int main()
{
    int a[4]{0, 1, 2, 3};
    std::vector<int> b(std::begin(a), std::end(a));

    for (auto i = b.begin(); i != b.end(); ++i)
        std::cout << *i;

    return 0;
}
