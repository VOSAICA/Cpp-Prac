#include <iostream>

using std::cout;

struct Employee
{
    static size_t idCount;

    Employee() : id(++idCount)
    {
    }

    Employee(const Employee& orgi) : id(++idCount)
    {
    }

    Employee& operator=(const Employee& rhs)
    {
        id = ++idCount;
        return *this;
    }

    int id;
};

size_t Employee::idCount = 0;

int main()
{
    Employee a, b = a, c = b;

    return 0;
}
// 理由与13.14，13.15，13.16相似
