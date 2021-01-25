#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

int main()
{
    vector<int> v;
    int a;
    while (cin >> a)
        v.emplace_back(a);
    for (auto a : v)
        cout << a << '\n';

    return 0;
}
