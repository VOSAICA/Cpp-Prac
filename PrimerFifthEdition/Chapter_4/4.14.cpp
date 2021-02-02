#include <iostream>

using std::cout;

int main()
{
    int i;

    // if (42 = i) //赋值运算符左侧对象必须是可修改的左值
    if (i = 42)
        cout << "i = 42";

    return 0;
}
