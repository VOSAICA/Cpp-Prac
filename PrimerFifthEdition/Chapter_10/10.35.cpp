#include <iostream>
#include <vector>

using std::cout;
using std::vector;

int main()
{
    vector<int> a{0, 5, 2, 4, 1};
    for (auto i = a.cend() - 1; i != a.cbegin() - 1; --i)
        cout << *i;

    return 0;
}
