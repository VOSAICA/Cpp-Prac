#include <iostream>
#include <memory>

using std::cout;
using std::shared_ptr;

struct destination
{
};

struct connection
{
};

connection connect(destination* d)
{
    return connection();
}

void disconnnect(connection)
{
}

void f(destination& d)
{
    connection c = connect(&d);
    shared_ptr<connection> p(&c, [](connection* pc) { disconnnect(*pc); });
}

int main()
{
    destination d;
    f(d);

    return 0;
}
