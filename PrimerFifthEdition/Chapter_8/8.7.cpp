#include "Sales_data1.h"
#include <fstream>
#include <iostream>

using std::endl;

int main()
{
    Sales_data total;
    std::ifstream ifs("8.7_Sales_data.txt");
    std::ofstream ofs("8.7_Out.txt");
    if (ifs >> total.bookNo >> total.revenue)
    {
        Sales_data trans;

        while (ifs >> trans.bookNo >> trans.revenue)
        {
            if (total.bookNo == trans.bookNo)
                total.revenue += trans.revenue;
            else
            {
                ofs << "Not same book" << endl;
                total = trans;
            }
        }
        ofs << total.revenue << endl;
    }
    else
        ofs << "No data?!" << endl;

    return 0;
}
