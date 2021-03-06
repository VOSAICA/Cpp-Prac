// 声明并初始化一个字符串
// 使用字符串初始化一个Sales_data
// 隐式将字面值字符串转换为字符串，然后用字符串初始化一个Sales_data

//没有问题

#include "Sales_data11.h"
#include <iostream>
#include <string>

using std::cout;
using std::string;

int main()
{
    string null_isbn("9-999-99999-9");
    Sales_data item1(null_isbn);
    Sales_data item2("9-999-99999-9");

    return 0;
}
