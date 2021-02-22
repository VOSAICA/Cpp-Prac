// Screen1.h
#include "Screen1.h"
#include <iostream>

using std::cout;

int main()
{
    Screen s1(12, 12, '*');
    s1.move(1, 3);
    s1.some_member();

    cout << s1.get();
    s1.some_member();

    cout << s1.get(5, 7);
    s1.some_member();

    return 0;
}
