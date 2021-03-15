#include <iostream>
#include <list>

using std::cout;
using std::list;

int main()
{
    list<int> c{5, 1, 2};
    list<int> d{5, 1, 2};
    list<int> e{5, 1, 2};

    c.erase(c.begin(), c.begin());
    d.erase(d.begin(), d.end());
    e.erase(e.end(), e.end());

    for (auto i : c)
        cout << i;
    cout << '\n';

    for (auto i : d)
        cout << i;
    cout << '\n';

    for (auto i : e)
        cout << i;

    return 0;
}
