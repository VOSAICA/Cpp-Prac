#include <iostream>
#include <string>

class HasPtr
{
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

int main()
{
    auto a = HasPtr("A string");
    auto b = a;
    auto c = HasPtr();
    a = c;
    b = c;

    return 0;
}
