// 下标里是关键字类型，返回map的值类型

#include <iostream>
#include <map>

using std::cout;
using std::map;

int main()
{
    map<int, bool> a({{1, true}, {2, false}});
    cout << a[1] << a.at(2) << a[3] << '\n';
    cout << a.at(4);

    return 0;
}
