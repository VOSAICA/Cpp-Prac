#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::string;
using std::vector;

bool is_longer(const string& s1, const string& s2) // 传引用，减少拷贝
{
    return s1.size() > s2.size();
}

void print(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    for (std::vector<int>::iterator iter = begin; iter != end; ++iter)
        std::cout << *iter << std::endl;
}

int main()
{
    string a{"lloonnggeerr"}, b{"shorter"};
    cout << is_longer(a, b) << '\n';

    vector<int> c{1, 2, 3, 4, 5};
    print(c.begin(), c.end());

    return 0;
}
