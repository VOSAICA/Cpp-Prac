#include <forward_list>
#include <iostream>
#include <list>

using std::cout;
using std::forward_list;
using std::list;

int main()
{
    list<int> li = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto iter = li.begin();
    while (iter != li.end())
    {
        if (*iter % 2)
        {
            iter = li.insert(iter, *iter);
            ++iter;
            ++iter;
        }
        else
            iter = li.erase(iter);
    }

    for (auto i : li)
        cout << i << ' ';
    cout << '\n';

    forward_list<int> fli = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto prev = fli.before_begin();
    auto curr = fli.begin();
    while (curr != fli.end())
    {
        if (*curr % 2 == 1)
        {
            curr = fli.insert_after(curr, *curr);
            ++curr;
            ++prev;
            ++prev;
        }
        else
            curr = fli.erase_after(prev);
    }
    for (auto i : fli)
        cout << i << ' ';

    return 0;
}
