#include <iostream>
#include <list>
#include <vector>

using std::cout;
using std::list;
using std::vector;

int main()
{
    list<int> a{0, 1, 2, 3};
    vector<double> b(a.begin(), a.end());

    vector<int> c{9, 1, 2, 3};
    vector<double> d(c.begin(), c.end());

    for (auto i : b)
        cout << i << ' ';
    cout << std::endl;

    for (auto i : d)
        cout << i << ' ';
    cout << std::endl;

    return 0;
}
