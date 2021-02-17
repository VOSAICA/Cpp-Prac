#include <iostream>

using std::cout;

int* getPtr()
{
    return nullptr;
}

int main()
{
    int i = 0;
    int* p;

    if (auto p = getPtr() != 0) // 这里是先运算的getPtr() != 0, 再把布尔值赋值给p, if判断的是p的布尔值
        cout << "getPtr()返回的不是0";

    if ((p = getPtr()) != 0)
        cout << "p is not a nullptr";

    if (i = 1024)
        cout << i << '\n';

    if (i == 1024)
        cout << "i == 1024";

    return 0;
}
