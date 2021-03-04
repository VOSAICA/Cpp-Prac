#include <iostream>
#include <vector>

using std::cout;
using std::vector;

class NoDefault
{
public:
    NoDefault(int a) : member(a)
    {
    }

    int member;
};

class C
{
public:
    C() : member(NoDefault(6))
    {
    }

    NoDefault member;
};

int main()
{
    vector<C> vec(10); // vec长度为10，每个都默认初始化，但NoDefault类没有默认构造函数

    cout << vec[0].member.member;
    return 0;
}
