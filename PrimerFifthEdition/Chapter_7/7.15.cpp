// Person5.h
#include "Person5.h"
#include <iostream>

int main()
{
    Person a(std::cin), b("Bob", "Tianjing");
    print(print(std::cout, a), b);

    return 0;
}
