#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using std::cout;
using std::vector;

int main()
{
    vector<double> vin{1.5, 1.5};
    cout << std::accumulate(vin.cbegin(), vin.cend(), 0) << '\n'; // 输出为2

    cout << std::accumulate(vin.cbegin(), vin.cend(), 0e0); // 输出为3

    return 0;
}
