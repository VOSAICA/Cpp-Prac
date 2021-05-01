#include <iostream>
#include <string>

using std::cout;

class HasPtr
{
public:
    HasPtr(const std::string& s = std::string()) : ps(new std::string(s)), i(0)
    {
    }

    ~HasPtr()
    {
        cout << "destroyed" << '\n';
    }

    HasPtr(const HasPtr& orgi) : i(orgi.i)
    {
        ps = new std::string(*orgi.ps);
    }

    HasPtr& operator=(const HasPtr& rhs)
    {
        *ps = *rhs.ps;
        i = rhs.i;

        return *this;
    }

    std::string* ps;
    int i;
};

int main()
{
    HasPtr a("ABC");
    HasPtr b = a;
    HasPtr c("DEF");

    return 0;
}
