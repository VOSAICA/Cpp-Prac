#include "StrBlob.h"
#include <iostream>

int main()
{
    auto a = StrBlob{"a", "b", "cd"};
    auto ap = a.begin();
    ap.incr();
    ap.incr();
    std::cout << ap.deref() << '\n';
    ap = a.end();
    std::cout << ap.deref();

    return 0;
}
// g++ 12.19.cpp StrBlob.cpp -o 12.19.exe
