#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

int main()
{
    do
    {
        string a, b;
        cin >> a >> b;
        cout << (a.size() < b.size() ? a : b) << '\n';
    } while (cin);

    return 0;
}
