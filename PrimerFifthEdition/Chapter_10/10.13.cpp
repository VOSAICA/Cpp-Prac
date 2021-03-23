#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::string;
using std::vector;

bool define(string a)
{
    return a.size() < 5;
}

int main()
{
    vector<string> a{"nb", "qnmlgb", "arstdhneio", "qwfpgjluy", "kksk"};
    auto begin = std::partition(a.begin(), a.end(), define);

    for (auto i = begin; i != a.end(); ++i)
        cout << *i << ' ';

    return 0;
}
