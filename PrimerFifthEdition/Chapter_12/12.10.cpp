#include <iostream>
#include <memory>

using std::cout;
using std::shared_ptr;

void process(shared_ptr<int> ptr)
{
    cout <<"ptr.use_count(): " <<ptr.use_count() << '\n';
}

int main()
{
    shared_ptr<int> p(new int(42)); // 引用为1
    process(shared_ptr<int>(p));    // ptr引用为2，p引用为2
    // ptr被释放，p引用为1
    cout <<"p.use_count(): " <<p.use_count();

    return 0;
}
