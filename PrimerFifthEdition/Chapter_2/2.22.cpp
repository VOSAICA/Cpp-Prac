#include <iostream>

int main()
{
    int a = 1, *p = 0, *p2 = &a;

    if (p)
        std::cout << "p is not an null pointer"
                  << "\n";
    if (*p2)
        std::cout << "value pointed by p2 is not 0";

    return 0;
}
