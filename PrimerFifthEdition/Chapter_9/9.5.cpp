#include <iostream>
#include <vector>

using std::cout;
using std::vector;

vector<int>::const_iterator func(vector<int>::const_iterator a, vector<int>::const_iterator b, int value)
{
    while (a != b)
    {
        if (*a == value)
            return a;
        ++a;
    }
    return b;
}

int main()
{
    vector<int> vec{9, 1, 2, 3, 4, 5, 7, 1, 0};
    cout << *func(vec.begin(), vec.end(), 9) << '\n';
    cout << *func(vec.begin(), vec.end(), 8);

    return 0;
}
