#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

int main()
{
    string a;
    cin >> a;

    int i;
    while (a[i])
    {
        a[i] = 'X';
        ++i;
    }
    cout << a;

    return 0;
}
//👴觉得for好点，但不知道为啥。
