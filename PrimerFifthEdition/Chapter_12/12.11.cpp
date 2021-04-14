#include <iostream>
#include <memory>

using std::cout;
using std::shared_ptr;

void process(shared_ptr<int> ptr)
{
}

int main()
{
    shared_ptr<int> p(new int(42)); // 引用为1
    process(shared_ptr<int>(p));    // p引用为2，ptr引用为2
    cout << *p << '\n';

    process(shared_ptr<int>(p.get())); // p引用为1，ptr引用为1
    // ptr被释放，p无效了
    cout << *p;

    return 0;
}
