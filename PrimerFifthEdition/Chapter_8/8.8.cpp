#include "Sales_data1.h"
#include <fstream>
#include <iostream>

using std::endl;

int main()
{
    Sales_data total;
    std::ifstream ifs("8.8_Sales_data.txt");
    std::ofstream ofs;
    ofs.open("8.8_Out.txt", std::ofstream::app);
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
