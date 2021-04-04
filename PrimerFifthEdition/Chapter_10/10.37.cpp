#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

using std::cout;
using std::list;
using std::vector;

int main()
{
    vector<int> a{0, 5, 0, 4, 1, 2, 7, 9, 4, 3};
    list<int> b(a.rbegin() + 3, a.rbegin() + 8);

    for (auto i : b)
        cout << i << ' ';

    return 0;
}
