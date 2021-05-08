// 拷贝构造：新创建一个shared_ptr，而不是拷贝一个
// 拷贝复制：新建shared_ptr

#include "StrBlob.h"
#include <iostream>

using std::cout;

int main()
{
    StrBlob a{"SB", "NM$L"};
    StrBlob b = a;
    StrBlob c;

    a.front() = "BSB";
    cout << a.begin().deref() << '\n';
    cout << b.begin().deref() << '\n';
    c = b;
    b.front() = "CSB";
    cout << c.begin().deref();

    return 0;
}
