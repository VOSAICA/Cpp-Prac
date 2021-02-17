#include <iostream>
#include <vector>

using std::cout;
using std::vector;

int func(int, int)
{
    return 0;
}

using functype = decltype(func);
// using functype = int(int, int); 同上

using funcPtrType = decltype(func)*;
// using funcPtrType = int (*)(int, int);

funcPtrType funcPtr = func;

int main()
{
    vector<functype*> funcVec;

    int (*a)(int, int);
    a = func;

    funcPtrType b = func;

    funcVec.emplace_back(a);
    funcVec.emplace_back(b);

    return 0;
}
