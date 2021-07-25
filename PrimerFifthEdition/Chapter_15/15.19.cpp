#include <iostream>

class BaseClass
{
public:
    long pub_mem;

    void memfcn(BaseClass& b)
    {
        b = *this;
    }

    // 对Pub_Derv, Priv_Derv和Prot_Derv合法
    // 不管已什么方式继承，友元和成员函数都可以使用派生类向基类的转换

    // 对Derived_from_Public和Derived_from_Protected合法
    // 公有和保护继承时，派生类的派生类的成员函数和友元可以使用向基类的转换

    // 对Derived_from_Private不合法
    // 私有继承时，派生类的派生类的成员函数和友元不能使用向基类的转换

private:
    char priv_mem;

protected:
    int prot_mem;
};

struct Pub_Derv : public BaseClass
{
    int f()
    {
        return pub_mem; // public
    }

    char g()
    {
        return priv_mem; // 不可访问
    }

    int s()
    {
        return prot_mem; // protected
    }
};

struct Priv_Derv : private BaseClass
{
    int f() const
    {
        return pub_mem; // private
    }

    char g()
    {
        return priv_mem; // 不可访问
    }

    int s()
    {
        return prot_mem; // private
    }
};

struct Prot_Derv : protected BaseClass
{
    int f() const
    {
        return pub_mem; // protected
    }

    char g()
    {
        return priv_mem; // 不可访问
    }

    int s()
    {
        return prot_mem; // protected
    }
};

struct Derived_from_Public : public Pub_Derv
{
};

struct Derived_from_Private : public Priv_Derv
{
};

struct Derived_from_Protected : public Prot_Derv
{
};
