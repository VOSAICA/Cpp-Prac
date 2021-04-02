#include <iostream>
#include <vector>

using std::cout;
using std::vector;

int main()
{
    vector<int> a{0, 5, 2, 4, 1};
    for (auto i = a.crbegin(); i != a.crend(); ++i)
        cout << *i;

    return 0;
}
