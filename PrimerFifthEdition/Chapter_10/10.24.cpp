#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std::placeholders;

using std::bind;
using std::cout;
using std::string;
using std::vector;

bool check_size(const int& a, string::size_type sz)
{
    return a >= static_cast<int>(sz);
}

int main()
{
    vector<int> inv{3, 1, 2, 6, 7};
    auto iter = std::find_if(inv.begin(), inv.end(), bind(check_size, _1, string("four").length()));

    cout << *iter;

    return 0;
}
