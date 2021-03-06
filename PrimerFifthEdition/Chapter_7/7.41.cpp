// Sales_data10.h
#include "Sales_data10.h"
#include <iostream>

using std::cin;
using std::cout;

Sales_data first_item(cin); // Sales_data(std::istream& is)

int main()
{
    Sales_data next;                  // Sales_data() : Sales_data("Default", 0, 0)
    Sales_data last("0-999-99999-9"); // Sales_data(const std::string s) : Sales_data(s, 0, 0)

    print(cout, next); // Default 0 0 0
    print(cout, last); // 0-999-99999-9 0 0 0

    return 0;
}
