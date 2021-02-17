#include <iostream>

using std::cout;

int& ng()
{
    int a = 100;
    int& b = a;
    return b; // 不要返回局部变量的引用或指针
}

const int& ng2()
{
    const int a = 10;
    const int& b = a;
    return b;
}

int main()
{
    const int& k = ng2();
    cout << k << ' ' << k;

    return 0;
}
