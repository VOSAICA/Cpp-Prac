#include <iostream>

using std::cout;

int main()
{
    double dval;
    int ival;
    int* pi;
    // dval = ival = pi = 0; //不能把空指针赋值给整形
    dval = ival = 0;
    pi = 0;
    cout << dval << ' ' << ival << ' ' << pi;

    return 0;
}
