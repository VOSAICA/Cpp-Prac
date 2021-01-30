#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

int main()
{
    string a, total;
    while (cin >> a)
    {
        total += a + ' ';
    }
    cout << total;

    return 0;
}
