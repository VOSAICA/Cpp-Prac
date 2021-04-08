#include <iostream>
#include <string>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
using std::pair;
using std::string;
using std::vector;

int main()
{
    using myPair = pair<string, int>;

    vector<myPair> vp;
    string a;
    int b;

    while (cin >> a >> b)
    {
        vp.emplace_back(a, b); // 这个最方便
        // vp.push_back({a, b});
        // vp.push_back(std::make_pair(a, b));
    }

    for (auto i : vp)
        cout << i.first << ' ' << i.second << '\n';

    return 0;
}
