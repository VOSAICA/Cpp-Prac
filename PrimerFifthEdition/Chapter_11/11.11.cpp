#include "Sales_item.h"
#include <iostream>
#include <set>
#include <string>

using std::string;
using std::cout;
using std::multiset;

bool smallerIsbn(const Sales_item& lhs, const Sales_item& rhs)
{
    return lhs.isbn() < rhs.isbn();
}

int main()
{
    multiset<Sales_item, bool(*)(const Sales_item&, const Sales_item&)> bookstore(smallerIsbn);

    bookstore.emplace("BBB");
    bookstore.emplace("MB");
    bookstore.emplace("AB");
    bookstore.emplace("BB");
    bookstore.emplace("BBB");

    cout << *bookstore.begin() << '\n';
    cout << *--bookstore.end();

    return 0;
}
