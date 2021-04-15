#include <iostream>
#include <memory>

using std::cout;
using std::unique_ptr;

int main()
{
    int ix = 1024;
    int* pi = &ix;
    int* pi2 = new int(2048);

    using IntP = unique_ptr<int>;

    IntP p0(ix);            //得用指针
    IntP p1(pi);            //不是new返回的指针
    IntP p2(pi2);           // unique_ptr释放资源后，p2成dangling pointer
    IntP p3(&ix);           // 不是new返回的指针
    IntP p4(new int(2048)); // 没问题
    IntP p5(p2.get());      // 不应该用get初始化智能指针

    return 0;
}
