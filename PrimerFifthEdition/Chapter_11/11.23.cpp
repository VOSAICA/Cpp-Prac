#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::multimap;
using std::string;
using std::vector;

int main()
{
    multimap<string, string> families;
    string kid, family;

    while (cin >> family >> kid)
        families.emplace(family, kid);

    for (const auto& i : families)
        cout << i.first << " " << i.second << '\n';

    return 0;
}
