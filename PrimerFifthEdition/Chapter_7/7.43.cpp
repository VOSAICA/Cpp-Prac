#include <iostream>

using std::cout;

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
    C() : member(NoDefault(0))
    {
    }

    NoDefault member;
};

int main()
{
    C c;
    cout << c.member.member;

    return 0;
}
