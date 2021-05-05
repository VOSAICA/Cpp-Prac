#include <iostream>

using std::cout;

struct Employee
{
    static size_t idCount;

    Employee() : id(++idCount)
    {
    }

    int id;
};

size_t Employee::idCount = 0;

int main()
{
    Employee a, b = a, c = b;

    return 0;
}
