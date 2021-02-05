#include <iostream>

using std::cout;

int main()
{
    char cval;
    int ival;
    unsigned int ui;
    float fval;
    double dval;

    cval = 'a' + 3;
    fval = ui - ival * 1.0;//ival 转换为unsigned int
    dval = ui * fval;//
    cval = ival + fval + dval;

    return 0;
}
