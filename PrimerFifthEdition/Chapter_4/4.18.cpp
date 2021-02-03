#include <iostream>
#include <vector>

using std::cout;
using std::vector;

int main()
{
    vector<int> v{3, 4, 5};

    auto pbeg = v.begin();

    while (pbeg != v.end())
        cout << *pbeg++ << std::endl; //递增运算符优先于解引用运算符

    pbeg = v.begin();
    while (pbeg != v.end())
        cout << *++pbeg << std::endl; //打印不了第一个，最后迭代器会超出vector

    return 0;
}
