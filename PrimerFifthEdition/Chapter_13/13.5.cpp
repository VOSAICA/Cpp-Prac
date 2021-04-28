#include <iostream>
#include <string>

using std::cout;

class HasPtr
{
public:
    HasPtr(const std::string& s = std::string()) : ps(new std::string(s)), i(0)
    {
    }

    HasPtr(const HasPtr& orgi) : i(orgi.i)
    {
        ps = new std::string(*orgi.ps);
    }

    std::string* ps;
    int i;
};

int main()
{
    HasPtr a("ABC");
    HasPtr b = a;

    *a.ps = "sb";
    cout << *b.ps;

    return 0;
}
