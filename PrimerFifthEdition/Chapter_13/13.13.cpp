#include <iostream>
#include <vector>

struct X
{
    X()
    {
        std::cout << "X()" << std::endl;
    }
    X(const X&)
    {
        std::cout << "X(const X&)" << std::endl;
    }
    X& operator=(const X& rhs)
    {
        std::cout << "operator=" << std::endl;
        return *this;
    }
    ~X()
    {
        std::cout << "~X()" << std::endl;
    }
};

int main()
{
    X x1;
    X x2 = x1;
    x1 = x2;

    std::vector<X> vx{x1, x2};
    ;

    return 0;
}
