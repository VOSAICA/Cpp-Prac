#include <iostream>
//#include <cstddef>

int main()
{
    int ia[3][4] = {1, 2, 3, 4, 3, 4, 5, 6, 2, 3, 4, 5};

    for (auto& p : ia)
    {
        for (auto q : p)
            std::cout << q;
        std::cout << std::endl;
    }
    std::cout << std::endl;

    for (auto i = 0; i != 3; i++)
    {
        for (auto j = 0; j != 4; ++j)
            std::cout << ia[i][j];
        std::cout << std::endl;
    }
    std::cout << std::endl;

    for (auto p = ia; p != ia + 3; ++p)
    {
        for (auto q = *p; q != *p + 4; ++q)
            std::cout << *q;
        std::cout << std::endl;
    }

    return 0;
}
