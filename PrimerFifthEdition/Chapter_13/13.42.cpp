#include "StrBlob.h"
#include <iostream>

int main()
{
    StrBlob sb;
    sb.push_back("SB");
    std::cout << sb.begin().deref() << '\n';
    sb.pop_back();
    std::cout << sb.size();

    return 0;
}
