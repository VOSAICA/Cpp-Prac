#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

using std::cin;
using std::cout;
using std::list;
using std::vector;

int main()
{
    vector<int> vec;
    list<int> lst;
    int i;

    while (cin >> i)
        lst.push_back(i);
    std::copy(lst.cbegin(), lst.cend(), std::back_inserter(vec));

    vector<int> vec2;
    std::fill_n(std::back_inserter(vec2), 10, 0);

    for (auto i : vec)
        cout << i << ' ';
    cout << '\n';
    for (auto i : vec2)
        cout << i << ' ';

    return 0;
}
