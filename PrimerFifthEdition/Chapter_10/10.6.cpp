#include <algorithm>
#include <iostream>
#include <iterator>

#include <vector>

using std::cout;
using std::vector;

int main()
{
    int a[] = {1, 2, 3, 4, 5, 5, 2, 7, 3, 1, 2, 1, 2, 4, 1};
    std::fill_n(std::begin(a), std::end(a) - std::begin(a), 0);

    for (auto i : a)
        cout << i << ' ';

    return 0;
}
