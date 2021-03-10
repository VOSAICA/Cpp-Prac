#include <list>

using std::list;

int main()
{
    list<int> lst1;
    list<int>::iterator iter1 = lst1.begin(), iter2 = lst1.end();

    while (iter1 < iter2) // list的迭代器不支持<,改用vector或者array
    {
    }

    return 0;
}
