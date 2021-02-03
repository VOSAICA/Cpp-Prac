#include <iostream>
#include <vector>

using std::cout;
using std::vector;

int main()
{
    vector<int> ivec{0, 1, 2, 3};
    vector<int>::size_type cnt = ivec.size();
    for (vector<int>::size_type ix = 0; ix != ivec.size(); ++ix, --cnt)
        ivec[ix] = cnt;

    cnt = ivec.size();
    for (vector<int>::size_type ix = 0; ix != ivec.size(); ix++, cnt--)
        ivec[ix] = cnt;

    for (auto i : ivec)
        cout << i << ' ';

    return 0;
}
