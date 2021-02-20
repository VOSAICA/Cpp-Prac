// Person6.h
#include "Person6.h"
#include <iostream>

int main()
{
    Person a(std::cin), b("Bob", "Tianjing");
    print(print(std::cout, a), b);

    std::cout << a.name; // name已经是private了，不可访问

    return 0;
}
