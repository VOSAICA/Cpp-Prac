#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

int main()
{
    string a;
    cin >> a;

    for (auto& chara : a)
    {
        chara = 'X';
    }
    cout << a;

    return 0;
}
