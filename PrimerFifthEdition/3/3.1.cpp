#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

struct Sales_data
{
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int main()
{
    int start, end;
    cin >> start >> end;
    ++start;
    while (start < end)
    {
        cout << start << " ";
        ++start;
    }
    cout << endl;

    Sales_data book, total;

    while (cin >> book.bookNo >> book.units_sold >> book.revenue)
    {
        total.units_sold += book.units_sold;
        total.revenue += book.revenue;
    }
    total.bookNo = book.bookNo;

    cout << total.bookNo << '\n'
         << total.units_sold << '\n'
         << total.revenue << endl;

    return 0;
}
