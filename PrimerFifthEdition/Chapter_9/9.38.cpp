#include <iostream>
#include <vector>

using std::cout;
using std::vector;

int main()
{
    vector<int> a;
    a.reserve(5);
    cout << a.capacity() << ' ';

    for (int i = 0; i < 5; ++i)
        a.push_back(0);
    cout << a.capacity() << ' ';
    a.push_back(0);
    cout << a.capacity();
    // 预留空间翻倍

    return 0;
}
