#include <iostream>
#include <map>

using std::cout;
using std::map;

int main()
{
    map<int, int> a;
    a.emplace(1, 2);
    a.emplace(2, 3);
    a.begin()->second = 3;

    cout << a.begin()->second;

    return 0;
}
