#include <iostream>
#include <vector>

using std::cout;
using std::vector;

void print(const vector<int> &vec, vector<int>::size_type index)
{
    if (index == vec.size())
        return;
    else
    {
        cout << vec[index];
        print(vec, index + 1);
    }
}

int main()
{
    vector<int> vec{0, 2, 4, 1, 6, 7, 3};
    print(vec, 0);

    return 0;
}
