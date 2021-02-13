#include <iostream>
#include <string>

using std::cout;
using std::string;

string (&func(string (&a)[10]))[10]
{
    return a;
}

int main()
{
    string a = "abc";
    string b[10]{a + "d", a, a, a, a, a, a, a, a, a};

    string(&c)[10] = b;

    cout << *func(c);
    return 0;
}
