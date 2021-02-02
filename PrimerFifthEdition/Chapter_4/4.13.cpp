#include <iostream>

using std::cout;

int main()
{
    int i;
    double d;

    d = i = 3.5; //右结合律，i = 3.5作为d的右侧运算对象，赋值运算返回左侧运算对象，等价于i = 35; d = i;
    cout << i << ' ' << d << '\n';

    i = d = 3.5;
    cout << i << ' ' << d;

    return 0;
}
