#include "Sales_data.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    Sales_data total;
    if (cin >> total.bookNo >> total.revenue)
    {
        Sales_data trans;

        while (cin >> trans.bookNo >> trans.revenue)
        {
            if (total.bookNo == trans.bookNo)
                total.revenue += trans.revenue;
            else
            {
                cout << "Not same book" << std::endl;
                total = trans;
            }
        }
        cout << total.revenue << endl;
    }
    else
        std::cerr << "No data?!" << endl;

    return 0;
}
