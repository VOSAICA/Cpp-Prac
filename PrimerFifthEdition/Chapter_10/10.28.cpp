#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

using std::cout;
using std::list;
using std::vector;

int main()
{
    vector<int> inv{1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> li1, li2, li3;
    std::unique_copy(inv.cbegin(), inv.cend(), std::front_inserter(li1));
    std::unique_copy(inv.cbegin(), inv.cend(), std::back_inserter(li2));
    std::unique_copy(inv.cbegin(), inv.cend(), std::inserter(li3, li3.begin()));

    for (auto i : li1)
        cout << i << ' ';
    cout << '\n';

    for (auto i : li2)
        cout << i << ' ';
    cout << '\n';

    for (auto i : li3)
        cout << i << ' ';

    return 0;
}
