#include <iostream>
#include <vector>

using std::cout;
using std::vector;

int main()
{
    int *ptr = nullptr;
    vector<int> vec{2, 3, 4, 5, 6};
    int ival = 0;

    ptr != 0 && *ptr++; // ptr不为空指针同时ptr指向的整形不为0，ptr指向下一个位置。（递增运算符优先度高于解引用运算符，但是后置递增运符返回增加前的对象）

    ival++ &&ival; //ival不为0，ival = ival + 1，然后ival不为0

    vec[ival++] <= vec[ival]; //vec的ival项小于ival+1项，ival = ival + 1

    return 0;
}
