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
    myPair a;

    while (cin >> a.first >> a.second)
    {
        vp.emplace_back(a);
    }

    for (auto i : vp)
        cout << i.first << ' ' << i.second << '\n';

    return 0;
}
