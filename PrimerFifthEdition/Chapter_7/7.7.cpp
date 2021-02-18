#include "Sales_data3.h"
#include <iostream>

using std::cin;
using std::cout;

int main()
{
    Sales_data a, b, c;
    read(cin, a);
    read(cin, b);

    c = add(a, b);
    print(cout, c);

    return 0;
}
