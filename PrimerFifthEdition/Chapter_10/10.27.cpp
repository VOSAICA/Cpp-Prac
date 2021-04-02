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
    vector<int> inv{0, 2, 3, 4, 5, 6, 1, 3, 4, 5, 6};
    list<int> li{};
    std::unique_copy(inv.cbegin(), inv.cend(), std::front_inserter(li));

    for (auto i : li)
        cout << i << ' ';

    return 0;
}
