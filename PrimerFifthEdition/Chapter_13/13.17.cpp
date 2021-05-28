#include <iostream>

using std::cout;

size_t count = 0;

struct Employee
{
    Employee() : id(++count)
    {
    }

    Employee(const Employee& orgi) : id(++count)
    {
    }

    Employee& operator=(const Employee& rhs)
    {
        id = ++count;
        return *this;
    }

    int id;
};

void f(Employee& s)
{
    cout << s.id << '\n';
}

int main()
{
    Employee a, b = a, c = b;
    f(a);
    f(b);
    f(c);

    return 0;
}
