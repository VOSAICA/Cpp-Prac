#include "Sales_data3.h"
#include <iostream>

using std::cin;
using std::cout;

int main()
{
    Sales_data data1, data2;
    if (read(read(cin, data1), data2)) // 先读data1，再读data2
    {
        print(cout, data1);
        print(cout, data2);
    }

    return 0;
}
