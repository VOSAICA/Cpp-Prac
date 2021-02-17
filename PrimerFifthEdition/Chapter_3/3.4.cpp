#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string a, b;
    cin >> a >> b;

    if (a < b)
        cout << b << endl;
    else
        cout << a << endl;

    cin >> a >> b;
    if (a.size() < b.length()) // size 和 length在实现上没有区别
        cout << b;
    else
        cout << a;

    return 0;
}
