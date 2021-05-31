#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::vector;

struct HasPtr
{
    friend void swap(HasPtr& lhs, HasPtr& rhs);

    friend bool operator<(const HasPtr& lhs, const HasPtr& rhs);

    HasPtr(const std::string& s = std::string()) : value(0), pStr(new std::string(s))
    {
    }

    HasPtr(const HasPtr& orgi) : value(orgi.value), pStr(new std::string(*orgi.pStr))
    {
    }

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

bool operator<(const HasPtr& lhs, const HasPtr& rhs)
{
    return lhs.value < rhs.value;
}

int main()
{
    HasPtr a("asb"), b("back"), c("csp");
    vector<HasPtr> vec{c, a, b};

    std::sort(vec.begin(), vec.end()); //傻逼

    return 0;
}
