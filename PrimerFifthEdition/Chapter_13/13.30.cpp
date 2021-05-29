#include <iostream>
#include <string>

using std::cout;

struct HasPtr
{
    friend void swap(HasPtr& lhs, HasPtr& rhs);

    HasPtr(const std::string& s = std::string()) : value(0), pStr(new std::string(s))
    {
    }

    HasPtr(const HasPtr& orgi) : value(orgi.value), pStr(new std::string(*orgi.pStr))
    {
    }

    // 大部分情况组合了析构函数和拷贝构造函数的工作
    HasPtr& operator=(HasPtr rhs)
    {
        swap(rhs, *this); // rhs先被拷贝构造，调用结束后rhs被销毁，调用析构函数，delete了rhs的指针
        return *this;
    }

    ~HasPtr()
    {
        delete pStr;
    }

    int value;
    std::string* pStr;
};

void swap(HasPtr& lhs, HasPtr& rhs)
{
    using std::swap;
    std::cout << "swapping\n";
    swap(lhs.value, rhs.value);
    swap(lhs.pStr, rhs.pStr);
}

int main()
{
    HasPtr a("asb");
    HasPtr b("csp");
    swap(a, b);

    cout << *b.pStr << '\n';
    b = a;

    return 0;
}
