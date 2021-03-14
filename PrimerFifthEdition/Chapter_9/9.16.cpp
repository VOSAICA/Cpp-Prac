#include <iostream>
#include <list>
#include <vector>

using std::cout;
using std::list;
using std::vector;

bool smaller(const vector<int>& a, const vector<int>& b)
{
    return a < b ? true : false;
}

bool smaller(const list<int>& a, const vector<int>& b)
{
    vector<int> newA;
    newA.assign(a.begin(), a.end());
    return newA < b ? true : false;
}

bool smaller(const vector<int>& a, const list<int>& b)
{
    vector<int> newB;
    newB.assign(b.begin(), b.end());
    return a < newB ? true : false;
}

int main()
{
    vector<int> a{1, 2, 3}, b{2, 3, 1};
    list<int> c{2, 3, 1};
    cout << smaller(a, b) << '\n';
    cout << smaller(c, b) << '\n';
    cout << smaller(b, c);

    return 0;
}
