#include <iostream>
#include <vector>

using std::cout;
using std::vector;

int main()
{
    vector<int> vi{0, 5, 7, 4, 6, 1, 8};
    auto iter = vi.begin();
    while (iter != vi.end())
    {
        if (*iter % 2 == 1)
        {
            iter = vi.insert(iter, *iter); // 这里返回的是插入后的前一个元素的位置，也就是说下标位置相同的元素
            ++iter;
        }
        ++iter;
    }

    for (auto i : vi)
        cout << i << ' ';

    return 0;
}
