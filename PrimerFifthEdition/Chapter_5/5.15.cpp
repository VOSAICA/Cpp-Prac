#include <iostream>

using std::cout;

int main()
{
    int sz = 1;
    for (int ix = 0; ix != sz; ++ix)
        if (ix != sz)
            ;

    int ix;
    for (; ix != sz; ++ix)
        ;

    for (int ix = 0; ix != sz; ++ix, ++sz) //死循环
        ;

    return 0;
}
