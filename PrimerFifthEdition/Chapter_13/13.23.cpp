#include <iostream>
#include <string>

using std::cout;

struct HasPtr
{
    HasPtr(const std::string& s = std::string()) : value(0), pStr(new std::string(s))
    {
    }

    HasPtr(HasPtr& orgi) : value(orgi.value), pStr(new std::string(*orgi.pStr))
    {
    }

    // 大部分情况组合了析构函数和拷贝构造函数的工作
    HasPtr& operator=(const HasPtr& rhs)
    {
        auto pStrNew = new std::string(*rhs.pStr); // 先拷贝右侧运算对象可以处理自赋值情况
        value = rhs.value;

        delete pStr;    // 释放左侧对象已经分配的内存
        pStr = pStrNew; // 更新指针

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
    b = b;
    cout << *b.pStr;

    return 0;
}
