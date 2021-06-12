#include <algorithm>
#include <vector>

using namespace std;

class Foo
{
public:
    Foo sorted() &&;
    Foo sorted() const&;

private:
    vector<int> data;
};

Foo Foo::sorted() &&
{
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
    return Foo(*this).sorted(); // 现在可以了
}

int main()
{
    Foo a;
    a.sorted();

    return 0;
}
