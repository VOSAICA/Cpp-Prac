#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> v;
    int a;
    while (cin >> a)
        v.emplace_back(a);

    for (auto it = v.begin(); it != v.end() - 1; ++it)
        cout << *it + *it + 1 << ' ';
    cout << '\n';

    auto end = v.end();
    for (auto it = v.begin(); it != v.begin() + v.size() / 2; ++it)
        cout << *it + *(v.end() - (it - v.begin() + 1)) << ' ';
    cout << endl;

    return 0;
}
