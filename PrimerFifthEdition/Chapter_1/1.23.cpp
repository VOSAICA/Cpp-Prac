#include "Sales_item.h"
#include <iostream>
#include <string>

int main()
{
    Sales_item book1, book2;

    int currVal = 0, val = 0;

    if (std::cin >> book1)
    {
        int cnt = 1;
        while (std::cin >> book2)
        {
            if (book1.isbn() == book2.isbn())
            {
                ++cnt;
            }
            else
            {
                book1 = book2;
                std::cout << cnt << "\n";
                cnt = 1;
            }
        }
        std::cout << cnt << "\n";
    }
    return 0;
}
