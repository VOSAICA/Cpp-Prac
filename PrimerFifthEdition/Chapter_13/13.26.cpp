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
