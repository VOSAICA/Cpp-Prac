#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;

int main()
{
    vector<string> v;
    string a;
    while (cin >> a)
        v.emplace_back(a);

    for (auto a : v)
        cout << a << '\n';

    return 0;
}
