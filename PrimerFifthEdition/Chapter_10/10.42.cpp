#include <algorithm>
#include <iostream>
#include <list>

using std::cout;
using std::list;

void elimDups(list<int>& nums)
{
    nums.sort();
    nums.unique();
}

int main()
{
    list<int> a{
        9, 7, 6, 7, 8, 2, 3, 2, 5, 1, 1, 10, 5, 6, 7, 2, 3, 4, 5, 1,
    };

    elimDups(a);
    cout << a.size() << '\n';
    for (auto i : a)
        cout << i << ' ';

    return 0;
}
