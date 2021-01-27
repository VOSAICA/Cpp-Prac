#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

int main()
{
    //Array
    int a[5];
    for (auto ptr_cur = std::begin(a); ptr_cur != std::end(a); ++ptr_cur)
        cin >> *ptr_cur;

    int b[5];
    for (auto &i : b)
        cin >> i;

    bool equal = true;
    auto ptr_a = std::begin(a);
    auto ptr_a_end = std::end(a);
    auto ptr_b = std::begin(b);
    while (ptr_a != ptr_a_end)
    {
        if (*ptr_a != *ptr_b)
            equal = false;
        ++ptr_a;
        ++ptr_b;
    }
    cout << (equal ? "equal\n" : "not equal\n");

    //Vector
    vector<int> a1(5), b1(5);
    for (auto &i : a1)
        cin >> i;
    for (auto &i : b1)
        cin >> i;
    cout << (a1 == b1 && a1.size() != 0 ? "equal\n" : "not equal\n");

    return 0;
}
