#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

int main()
{
    string a;
    char s;
    a.reserve(100);
    while (cin >> s)
        a.push_back(s);

    cout << a;

    return 0;
}
