#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using std::cout;
using std::multiset;
using std::string;
using std::vector;

int main()
{
    vector<string> v{"apple", "banana", "carrot"};
    multiset<string> c{"durian", "e..."};

    std::copy(v.begin(), v.end(), std::inserter(c, c.end()));
    for (auto i : c)
        cout << i << ' ';
    cout << '\n';

    // std::copy(v.begin(), v.end(), std::back_inserter(c)); //没有push_back成员函数

    std::copy(c.begin(), c.end(), std::inserter(v, v.end()));
    for (auto i : v)
        cout << i << ' ';
    cout << '\n';

    std::copy(c.begin(), c.end(), std::back_inserter(v));
    for (auto i : v)
        cout << i << ' ';
    cout << '\n';

    return 0;
}
