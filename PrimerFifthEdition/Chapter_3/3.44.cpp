#include <iostream>
// #include <cstddef>

// using int_array = int[4];
typedef int int_array[4];

int main()
{
    int ia[3][4] = {1, 2, 3, 4, 3, 4, 5, 6, 2, 3, 4, 5};

    for (int_array& p : ia)
    {
        for (int q : p)
            std::cout << q;
        std::cout << std::endl;
    }
    std::cout << std::endl;

    for (int_array* p = ia; p != ia + 3; ++p)
    {
        for (int* q = *p; q != *p + 4; ++q)
            std::cout << *q;
        std::cout << std::endl;
    }

    return 0;
}
