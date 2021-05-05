#include <iostream>

using std::cout;

size_t count = 0;

struct numbered
{
    numbered() : mysn(++count)
    {
    }

    numbered(numbered& orgi) : mysn(++count)
    {
    }

    numbered& operator=(const numbered& rhs)
    {
        mysn = ++count;
        return *this;
    }

    int mysn;
};

void f(numbered& s)
{
    cout << s.mysn << '\n';
}

int main()
{
    numbered a, b = a, c = b;
    f(a);
    f(b);
    f(c);

    return 0;
}
