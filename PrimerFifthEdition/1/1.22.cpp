#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item book, total;

    while (std::cin >> book)
    {
        total = book + total;
    }
    std::cout << total << std::endl;

    return 0;
}
