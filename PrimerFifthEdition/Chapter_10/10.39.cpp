// list的迭代器是双向迭代器
// vector是随机访问迭代器

#include <iostream>
#include <list>
#include <vector>

using std::cout;
using std::list;
using std::vector;

int main()
{
    list<int> li{0, 1, 2, 3, 4};
    auto a = li.begin();
    auto b = li.end();

    vector<int> ve{0, 1, 2, 3, 4};
    auto c = ve.begin();
    auto d = ve.end();

    cout << b - a; //没有匹配的运算符
    cout << d - c;

    return 0;
}
