// Sales_data5.h
#include "Sales_data5.h"
#include <iostream>

using std::cin;
using std::cout;

int main()
{
    Sales_data a;
    Sales_data b("BZD");
    Sales_data c("CNM", 12, 5);
    Sales_data d(cin);

    print(cout, a);
    print(cout, b);
    print(cout, c);
    print(cout, d);

    return 0;
}
