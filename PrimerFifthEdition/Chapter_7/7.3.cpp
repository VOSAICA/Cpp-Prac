#include "Sales_data2.h"
#include <iostream>

using std::cout;

int main()
{
    Sales_data a, b;
    a.bookNo = "ARST";
    a.revenue = 100;
    a.units_sold = 10;

    b.bookNo = "ARST";
    b.revenue = 500;
    b.units_sold = 50;

    a.combine(b);

    cout << a.isbn() << ' ' << a.revenue << ' ' << a.avg_price();

    return 0;
}
