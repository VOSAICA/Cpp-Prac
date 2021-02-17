#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

int main()
{
    string a;
    cin >> a;

    for (char& chara : a)
    {
        chara = 'X';
    }
    cout << a;

    return 0;
}
