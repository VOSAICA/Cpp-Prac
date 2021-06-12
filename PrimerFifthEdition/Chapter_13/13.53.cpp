// 因为先进行了拷贝构造然后再swap

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

    HasPtr(HasPtr&& p) noexcept : value(p.value), pStr(p.pStr)
    {
        p.pStr = nullptr;
    }

    HasPtr& operator=(const HasPtr& rhs)
    {
        if (&rhs == this)
        {
            this->value = rhs.value;
            this->pStr = rhs.pStr;
        }
        return *this;
    }

    HasPtr& operator=(HasPtr&& rhs) noexcept
    {
        if (&rhs == this)
        {
            this->value = rhs.value;
            this->pStr = rhs.pStr;
        }
        rhs.pStr = nullptr;
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
    HasPtr h1("h1");
    HasPtr h2("h2");

    h1 = h2;
    h1 = std::move(h2);

    return 0;
}
