#include <iostream>
#include <string>

class HasPtr
{
    friend void swap(HasPtr& lhs, HasPtr& rhs);

public:
    HasPtr(const std::string& s = std::string()) : ps(new std::string(s)), i(0), use(new std::size_t(1))
    {
    }
    HasPtr(const HasPtr& orgi) : ps(orgi.ps), i(orgi.i), use(orgi.use)
    {
        ++*use;
    }
    HasPtr& operator=(const HasPtr& rhs);
    ~HasPtr();

private:
    std::string* ps;
    int i;
    std::size_t* use;
};

HasPtr& HasPtr::operator=(const HasPtr& rhs)
{
    ++*rhs.use;
    if (--*use == 0)
    {
#ifndef NDEBUG
        std::cout << "deleting ps\ndeleting use\n";
#endif
        delete ps;
        delete use;
    }
    ps = rhs.ps;
    i = rhs.i;
    use = rhs.use;
    return *this;
}

HasPtr::~HasPtr()
{
#ifndef NDEBUG
    std::cout << "~HasPtr\n";
#endif
    if (--*use == 0)
    {
        delete ps;
        delete use;
    }
}

void swap(HasPtr& lhs, HasPtr& rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps); //调用的是std::swap()
    swap(lhs.i, rhs.i);   //调用的也是std::swap()
}

int main()
{
    HasPtr a("Alice"), b("Bob");
    swap(a, b);

    return 0;
}
