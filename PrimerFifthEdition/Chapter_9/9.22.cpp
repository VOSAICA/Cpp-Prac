// vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size() / 2;

// while (iter != mid)
//     if (*iter == some_val)
//         iv.insert(iter, 2 * some_val); // 一直在头位置insert，死循环， insert之后mid会失效

#include <iostream>
#include <vector>

using std::cout;
using std::vector;

int main()
{
    int some_val = 3;
    vector<int> iv = {3, 2, 3, 4, 5, 6};
    vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size() / 2;

    while (iter != mid)
    {
        if (*iter == some_val)
        {
            iter = iv.insert(iter, 2 * some_val) + 2;
            mid = iv.begin() + iv.size() / 2;
        }
        else
            ++iter;
    }

    for (auto i : iv)
        cout << i << ' ';

    return 0;
}
