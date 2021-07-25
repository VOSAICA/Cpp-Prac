#include <iostream>

class BaseClass
{
public:
    long pub_mem;

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

int main()
{
    Pub_Derv a;
    std::cout << a.pub_mem;

    Priv_Derv b;
    std::cout << b.pub_mem;

    Prot_Derv c;
    std::cout << c.pub_mem;

    Derived_from_Public d;
    Derived_from_Private e;
    Derived_from_Protected f;

    // From Here

    BaseClass* p = &a; // 公有继承时才能使用派生类向基类的转换
    p = &b;
    p = &c;

    p = &d;
    p = &e;
    p = &f;

    return 0;
}
