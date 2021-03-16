#include <iostream>
#include <vector>

using std::cout;
using std::vector;

int main()
{
    vector<int> v{0, 1, 2, 3, 4};
    auto begin = v.begin();

    while (begin != v.end())
    {
        ++begin;
        begin = v.insert(begin, 42); // 不重新赋值的话begin会失效
        ++begin;
    }

    for (auto i : v)
        cout << i << ' ';

    return 0;
}
