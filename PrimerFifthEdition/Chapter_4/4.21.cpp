#include <iostream>
#include <vector>

using std::cout;
using std::vector;

int main()
{
    vector<int> vec{1, 2, 3, 4, 5};

    for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); ++iter)
        *iter = (*iter % 2 == 0 ? *iter : 2 * *iter);

    for (auto i : vec)
        cout << i << ' ';

    return 0;
}
