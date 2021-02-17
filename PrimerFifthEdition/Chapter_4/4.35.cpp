#include <iostream>

using std::cout;

int main()
{
    char cval;
    int ival;
    unsigned int ui;
    float fval;
    double dval;

    cval = 'a' + 3; // char转换为int相加，然后转换为char进行初始化
    fval = ui - ival * 1.0; // ival转换为double相乘，然后unsigned int转换为double相减，转换为float进行初始化
    dval = ui * fval;          // unsigend int转换为float相乘，然后转换为double
    cval = ival + fval + dval; // float转换为double相加，int转换为double相加，转换为char

    return 0;
}
