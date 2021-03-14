#include <iostream>
#include <vector>

using std::cout;
using std::vector;

bool smaller(const vector<int>& a, const vector<int>& b)
{
    return a < b ? true : false;
}

int main()
{
    vector<int> a{1, 2, 3}, b{2, 3, 1};

    cout << smaller(a, b);

    return 0;
}
