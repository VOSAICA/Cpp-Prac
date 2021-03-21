#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using std::cout;
using std::vector;

int main()
{
    vector<int> vin{0, 1, 3, 4, 1, 2, 5, 4, 1, 2, 3, 4, 1, 2, 3, 1, 55, 1};
    cout << std::accumulate(vin.cbegin(), vin.cend(), 0);

    return 0;
}
