#include <iostream>
int main()
{
    int i = -1;
    int &r = 0; //非常量引用的初始值必须为左值
    int i2 = 0;

    int *const p2 = &i2;

    const int i1 = -1, &r = 0;

    const int *const p3 = &i; //不能通过修改*p3来修改i的值，但i还是变量，p3是常量指针，不能改p3指向的地址
    const int *p1 = &i2;      //不能通过修改*p1来修改i2的，但i2还是变量，p1是指向常量的指针，可以更改p1指向的地址，

    const int &const r2; //有点扯
    const int i3 = i, &r = i;

    return 0;
}
