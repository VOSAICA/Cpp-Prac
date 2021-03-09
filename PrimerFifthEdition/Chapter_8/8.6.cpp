#include "Sales_data1.h"
#include <fstream>
#include <iostream>

using std::cout;
using std::endl;

int main()
{
    Sales_data total;
    std::ifstream ifs("Sales_data.txt");
    if (ifs >> total.bookNo >> total.revenue)
    {
        Sales_data trans;

        while (ifs >> trans.bookNo >> trans.revenue)
        {
            if (total.bookNo == trans.bookNo)
                total.revenue += trans.revenue;
            else
            {
                cout << "Not same book" << endl;
                total = trans;
            }
        }
        cout << total.revenue << endl;
    }
    else
        std::cerr << "No data?!" << endl;

    return 0;
}
