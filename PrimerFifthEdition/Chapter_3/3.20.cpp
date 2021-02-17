#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> v;
    int a;
    while (cin >> a)
        v.emplace_back(a);

    // vector<int>::size_type v_size = v.size();
    auto v_size = v.size();

    for (decltype(v_size) i = 0; i < v_size - 1; ++i)
        cout << v[i] + v[i + 1] << ' ';
    cout << '\n';

    for (decltype(v_size) i = 0; i < v_size / 2; ++i)
        cout << v[i] + v[v_size - 1 - i] << ' ';
    cout << endl;

    return 0;
}
