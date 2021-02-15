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
    assert(cin); //输入Ctrl^Z的时候为false，被强制退出

    return 0;
}
