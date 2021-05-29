#include <iostream>
#include <string>

using std::cout;

class HasPtr
{
public:
    HasPtr(const std::string& s = std::string()) : ps(new std::string(s)), i(0)
    {
    }

    HasPtr(const HasPtr& orgi) : ps(new std::string(*orgi.ps)), i(orgi.i)
    {
    }

    HasPtr& operator=(const HasPtr& rhs)
    {
        if (this != &rhs)
        {
            std::string* temp_ps = new std::string(*rhs.ps);
            delete ps;
            ps = temp_ps;
            i = rhs.i;
        }

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

    *a.ps = "sb";
    cout << *b.ps << '\n';

    a = c;
    *c.ps = "nb";
    cout << *a.ps;

    return 0;
}
