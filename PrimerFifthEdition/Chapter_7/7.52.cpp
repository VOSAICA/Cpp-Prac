#include <iostream>
#include <string>

using std::cout;

struct Sales_data
{
    std::string bookNo;
    unsigned units_sold; //聚合类(Aggregate Class)不该有类内初始值
    double revenue;
};

int main()
{
    Sales_data item = {"978-0590353403", 25, 15.99};

    return 0;
}
