#include <iostream>
#include <vector>

using std::cout;
using std::vector;

int main()
{
    vector<int> c{};

    cout << c.at(0); // 会抛出out_of_range error
    cout << c[0];
    cout << c.front();
    cout << *c.begin();

    return 0;
}
