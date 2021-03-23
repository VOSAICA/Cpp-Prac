#include "Sales_data.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::string;
using std::vector;

bool compareIsbn(const Sales_data& a, const Sales_data& b)
{
    return a.isbn() < b.isbn();
}

int main()
{
    vector<Sales_data> vsd{Sales_data("1234"), Sales_data("2345"), Sales_data("0123"), Sales_data("1333")};
    std::sort(vsd.begin(), vsd.end(), compareIsbn);

    for (auto i : vsd)
        cout << i.isbn() << ' ';

    return 0;
}
