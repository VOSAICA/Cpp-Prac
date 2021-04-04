#include <iostream>
#include <list>
#include <algorithm>

#include <iterator>

using std::cout;
using std::list;

int main()
{
    list<int> a{0, 5, 0, 4, 1};
    const auto iter = std::find(a.crbegin(), a.crend(), 0);
    cout << std::distance(iter, a.crend());

    return 0;
}
