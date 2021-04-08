#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::map;
using std::pair;
using std::string;
using std::vector;

int main()
{
    map<string, vector<pair<string, string>>> families;
    string kid, family, birthday;

    while (cin >> family)
    {
        if (cin >> kid >> birthday)
            families[family].emplace_back(kid, birthday);
    }

    for (const auto& i : families)
    {
        cout << i.first << ": ";
        for (const auto& j : i.second)
            cout << j.first << ' ' << j.second;
        cout << '\n';
    }

    return 0;
}
