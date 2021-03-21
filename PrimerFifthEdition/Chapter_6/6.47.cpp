#include <cassert>
#include <iostream>
#include <vector>

using std::cout;
using std::vector;

void print(const vector<int>& vec, vector<int>::size_type index)
{
#ifndef NDEBUG
    std::clog << "vec's size: " << vec.size() << '\n';
#endif
    if (index == vec.size())
        return;
    else
    {
        cout << vec[index] << '\n';
        print(vec, index + 1);
    }
}

int main()
{
    vector<int> vec{0, 2, 4, 1, 6, 7, 3};
    print(vec, 0);

    return 0;
}
// 在编译时#define NDEBUG
// g++ -D NDEBUG 6.47.cpp
