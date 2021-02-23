// Screen3.h
#include "Screen3.h"
#include <iostream>

using std::cout;

int main()
{
    Screen myScreen(5, 5, 'X');
    myScreen.move(4, 0).display(cout).set('#');
    cout << '\n';
    myScreen.display(cout);
    cout << '\n';

    return 0;
}
