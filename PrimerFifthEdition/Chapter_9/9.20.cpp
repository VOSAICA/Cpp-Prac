#include <deque>
#include <iostream>
#include <list>
#include <string>

using std::cin;
using std::cout;
using std::deque;
using std::list;
using std::string;

int main()
{
    list<int> a;
    deque<int> odd, even;
    int temp;

    while (cin >> temp)
        a.push_back(temp);

    for (auto i = a.begin(); i != a.end(); ++i)
        *i % 2 == 0 ? even.push_back(*i) : odd.push_back(*i);

    for (auto i : odd)
        cout << i << ' ';
    cout << '\n';

    for (auto i : even)
        cout << i << ' ';
    cout << '\n';

    return 0;
}
