#include <iostream>
#include <vector>

using std::cout;
using std::vector;

int main()
{
    vector<int> a{0, 1, 1, 2};
    vector<int> b{0, 1, 1, 2, 3, 5, 8};

    vector<int>* shorter;
    vector<int>* longer;

    if (a.size() < b.size())
        shorter = &a, longer = &b;
    else
        shorter = &b, longer = &a;

    bool is_child = true;
    auto iter_l = longer->begin();
    for (auto iter_s = shorter->begin(); iter_s != shorter->end(); ++iter_s)
    {
        if (*iter_s != *iter_l)
            is_child = false;
        ++iter_l;
    }
    cout << is_child;

    return 0;
}
