#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Foo
{
public:
    Foo(const vector<int>& vi) : data(vi){};
    Foo sorted() &&;
    Foo sorted() const&;

    vector<int> data;
};

Foo Foo::sorted() &&
{
    cout << "rvalue used\n";
    sort(data.begin(), data.end());
    return *this;
}
/*
Foo Foo::sorted() const&
{
    Foo ret(*this);
    sort(ret.data.begin(), ret.data.end());
    return ret;
}
 */
Foo Foo::sorted() const&
{
    cout << "lvalue used\n";
    return Foo(*this).sorted(); // 现在可以了
}

int main()
{
    for (auto i : Foo(vector<int>{5, 9, 3}).sorted().data)
    {
        cout << i;
    }

    Foo a({1, 4, 2});
    a.sorted();

    return 0;
}
