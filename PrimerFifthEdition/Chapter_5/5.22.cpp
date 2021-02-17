#include <iostream>

using std::cout;

int get_size()
{
    return 0;
}

int main()
{

    /* begin:
    int sz = get_size();
    if (sz <= 0)
    {
        goto begin;
    } */

    int sz = get_size();
    while (sz <= 0)
        sz = get_size();

    return 0;
}
