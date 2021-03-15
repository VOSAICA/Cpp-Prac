#include <iostream>
#include <list>
#include <vector>

using std::cout;
using std::list;
using std::vector;

int main()
{
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    vector<int> va(std::begin(ia), std::end(ia));
    list<int> la(std::begin(ia), std::end(ia));

    auto it = va.begin();
    while (it != va.end())
        if (*it % 2 == 0)
            it = va.erase(it);
        else
            ++it;

    auto it2 = la.begin();
    while (it2 != la.end())
        if (*it2 % 2 == 1)
            it2 = la.erase(it2);
        else
            ++it2;

    for (auto i : va)
        cout << i << ' ';
    cout << '\n';

    for (auto i : la)
        cout << i << ' ';

    return 0;
}
