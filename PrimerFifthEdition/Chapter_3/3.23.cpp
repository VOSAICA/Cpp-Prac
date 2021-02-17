#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

int main()
{
    vector<int> v(10);
    for (auto& foo : v)
        cin >> foo;

    for (auto it = v.begin(); it != v.end(); ++it)
        *it *= 2;

    for (auto foo : v)
        cout << foo << ' ';

    return 0;
}
