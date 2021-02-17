#include <iostream>
#include <string>

using std::cout;
using std::string;

int main()
{
    cout << sizeof(bool) << '\n';
    cout << sizeof(char) << '\n';
    cout << sizeof(short) << '\n';
    cout << sizeof(int) << '\n';
    cout << sizeof(long) << '\n';
    cout << sizeof(float) << '\n';
    cout << sizeof(double) << '\n';
    cout << sizeof(int*) << '\n';
    cout << sizeof(short*);

    return 0;
}
