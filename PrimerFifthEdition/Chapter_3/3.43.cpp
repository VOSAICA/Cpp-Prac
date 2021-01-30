#include <iostream>
//#include <cstddef>

int main()
{
    int ia[3][4] = {1, 2, 3, 4, 3, 4, 5, 6, 2, 3, 4, 5};

    for (int(&p)[4] : ia) //引用必变数组退化为指针
    {
        for (int q : p)
            std::cout << q;
        std::cout << std::endl;
    }
    std::cout << std::endl;

    for (size_t i = 0; i != 3; i++)
    {
        for (size_t j = 0; j != 4; ++j)
            std::cout << ia[i][j];
        std::cout << std::endl;
    }
    std::cout << std::endl;

    for (int(*p)[4] = ia; p != ia + 3; ++p)
    {
        for (int *q = *p; q != *p + 4; ++q)
            std::cout << *q;
        std::cout << std::endl;
    }

    return 0;
}
