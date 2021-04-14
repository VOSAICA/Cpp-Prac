#include <iostream>
#include <memory>

using std::cout;
using std::make_shared;
using std::shared_ptr;

int main()
{
    auto sp = make_shared<int>();
    auto p = sp.get();
    delete p;

    cout << *sp; // sp已经由p释放，错误

    return 0;
}
