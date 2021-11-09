#include "ConstStrBlobPtr.h"
#include "StrBlob.h"

#include <iostream>

using std::cout;

int main()
{
    const StrBlob a{"America", "Brazil", "China"};
    ConstStrBlobPtr cpa(a);

    cout << cpa.deref();

    return 0;
}
// g++ 12.22.cpp StrBlob.cpp ConstStrBlob.cpp -o 12.22.exe
