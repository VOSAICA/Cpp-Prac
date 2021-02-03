#include <iostream>

using std::cout;

int main()
{
    int i = 0;
    cout << ++i << ' '; //返回递增之后的值，少一次操作
    cout << i++ << ' '; //返回递增之前的值，两次操作
    cout << i;

    return 0;
}
