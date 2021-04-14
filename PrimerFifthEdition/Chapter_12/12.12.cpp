#include <iostream>
#include <memory>

using std::cout;
using std::make_shared;
using std::shared_ptr;

void process(shared_ptr<int> ptr)
{
}

int main()
{
    auto p = new int();
    auto sp = make_shared<int>();

    process(sp);
    process(new int()); // 不支持隐式转换
    process(p);         // 同上
    process(shared_ptr<int>(p));

    return 0;
}
