#include <array>
#include <iostream>
#include <vector>

using std::array;
using std::cout;
using std::vector;

int main()
{
    array<char, 4> b{'a', 'b', 'c', '\\'};
    vector<int> a(b.begin(), b.end()); // 用两个迭代器初始化时，容器可以不一样，元素也可以不一样

    for (auto i : a)
    {
        cout << i << ' ';
    }

    return 0;
}
