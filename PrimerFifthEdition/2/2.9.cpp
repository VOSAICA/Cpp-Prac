#include <iostream>

int main()
{
    //std::cin >> int input_value;
    int input_value;
    std::cin >> input_value;

    //int i = {3.14}; //列表初始化不接受存在丢失信息风险的初始化
    int i = 3.14;

    //double salary = wage = 9999.99;
    double salary = 9999.99, wage = salary;

    int i = 3.14; //这个没问题

    return 0;
}
