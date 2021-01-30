#include <cstring>
#include <iostream>
#include <string>

using std::cout;
using std::string;

int main()
{
    string a = "abcde";
    string b = "abcde";

    const char c[6] = {'a', 'b', 'c', 'd', 'e', '\0'};
    const char d[6] = {'a', 'b', 'c', 'd', 'e', '\0'};

    cout << (a == b ? "equal" : "not equal") << '\n';
    cout << (strcmp(c, d) == 0 ? "equal" : "not equal");

    return 0;
}
