#include <iostream>
#include <vector>

using std::cout;
using std::vector;

char next_text()
{
    return 'a';
}
unsigned some_value()
{
    return 1;
}
int get_value()
{
    return 2;
}
int get_num()
{
    return 15;
}
int get_bufCnt()
{
    return 1024;
}

int main()
{
    //(a)
    unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
    char ch = next_text();
    switch (ch)
    {
    case 'a':
        aCnt++;
        break;
    case 'e':
        eCnt++;
        break;
    default:
        iouCnt++;
        break;
    }

    //(b)
    unsigned index = some_value();
    vector<int> ivec{3, 2, 1, 0};
    switch (index)
    {
    case 1: {
        int ix = get_value();
        ivec[ix] = index;
        break;
    }
    default: {
        int ix = ivec.size() - 1;
        ivec[ix] = index;
        break;
    }
    }

    //(c)
    unsigned evenCnt = 0, oddCnt = 0;
    int digit = get_num() % 10;
    switch (digit)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 9:
        oddCnt++;
        break;
    case 0:
    case 2:
    case 4:
    case 6:
    case 8:
        evenCnt++;
        break;
    }

    //(d)
    const unsigned ival = 512, jval = 1024, kval = 4096;
    unsigned bufsize;
    unsigned swt = get_bufCnt();
    switch (swt)
    {
    case ival:
        bufsize = ival * sizeof(int);
        break;
    case jval:
        bufsize = jval * sizeof(int);
        break;
    case kval:
        bufsize = kval * sizeof(int);
        break;
    }

    return 0;
}
