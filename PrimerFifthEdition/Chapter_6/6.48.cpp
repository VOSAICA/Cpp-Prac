#include <cassert>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

int main()
{
    string s, sought{"cnm"};
    while (cin >> s && s != sought)
    {
        cout << "ok";
    }
    assert(cin);

    return 0;
}
