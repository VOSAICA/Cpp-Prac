#include <iostream>
#include <vector>

using std::cout;
using std::vector;

int main()
{
    vector<int> a;

    vector<int> b{0, 0, 0, 0, 0};

    vector<int> c(5); // 0 0 0 0 0

    vector<int> d(5, 0); // 0 0 0 0 0

    vector<int> e(d.begin(), d.end());

    vector<int> f(b); // 等同于vector<int> f = b;

    return 0;
}
