#include <iostream>
#include <memory>

using std::cout;
using std::unique_ptr;

int main()
{
    unique_ptr<int> pa(new int(12));
    unique_ptr<int> pb(new int(16));

    unique_ptr<int> pc = new int(16); // 不存在从int到unique_ptr的适当构造函数
    pb = new int(12);                 // no match for operator=
    unique_ptr<int> pd(pa);           //无法引用函数
    pa = pb;                          // use of deleted function

    return 0;
}
