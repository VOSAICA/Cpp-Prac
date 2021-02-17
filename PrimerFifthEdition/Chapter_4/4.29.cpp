#include <iostream>

using std::cout;

int main()
{
    int x[10] = {0};
    int* p = x;
    cout << sizeof(x) / sizeof(*x) << '\n'; //数组（10个整形）大小/单个整形大小
    cout << sizeof(p) / sizeof(*p);         //指针大小/整形大小

    return 0;
}
