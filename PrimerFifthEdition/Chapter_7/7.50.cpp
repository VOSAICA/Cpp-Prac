// Person8.h

#include <iostream>

using std::cout;

namespace Person7
{
#include "Person7.h"
}
namespace Person8
{
#include "Person8.h"
}

int main()
{
    Person7::print(std::cout, std::cin);
    Person8::print(std::cout, std::cin); // Person8当中声明了 explicit Person(std::istream&);

    return 0;
}
