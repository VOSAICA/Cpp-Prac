#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::cout;
using std::map;
using std::string;
using std::vector;

int main()
{
    map<string, vector<int>> a({{"a", {1, 2, 3}}, {"b", {2, 3, 4}}});
    auto b = a.find("a");

    for (auto i : b->second)
        cout << i << ' ';

    return 0;
}
