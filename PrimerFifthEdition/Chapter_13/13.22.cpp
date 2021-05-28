#include <iostream>
#include <string>

using std::cout;

struct HasPtr
{
    HasPtr(const std::string& s = std::string()) : value(0), pStr(new std::string(s))
    {
    }

    HasPtr(const HasPtr& orgi) : value(orgi.value), pStr(new std::string(*orgi.pStr))
    {
    }

    HasPtr& operator=(const HasPtr& rhs)
    {
        pStr = new std::string(*rhs.pStr);
        value = rhs.value;
        return *this;
    }

    ~HasPtr()
    {
        delete pStr;
    }

    int value;
    std::string* pStr;
};

int main()
{
    HasPtr a("asb");
    HasPtr b = a;
    *a.pStr = "sb";
    cout << *b.pStr;

    return 0;
}
