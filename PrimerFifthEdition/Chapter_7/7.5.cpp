// Person2.h
#include "Person2.h"
#include <iostream>

using std::cout;

int main()
{
    Person a;
    a.address = "Tiananmen";
    cout << a.get_address();

    return 0;
}
