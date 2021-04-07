#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::map;
using std::string;
using std::vector;

int main()
{
    map<string, vector<string>> families;
    string kid, family;
    while (cin >> family)
    {
        if (cin >> kid)
            families[family].push_back(kid);
    }

    for(const auto& i : families)
    {
        cout << i.first << ": ";
        for(const auto& j : i.second)
            cout << j << ' ';
        cout << '\n';
    }

    return 0;
}
