#include <iostream>
#include <vector>

using std::cout;
using std::vector;

int main()
{
    vector<int> c{4};

    if (!c.empty())
    {
        auto val = *c.begin(), val2 = c.front();
        auto last = c.end();
        auto val3 = *(--last);
        auto val4 = c.back();

        cout << val << ' ' << val2 << ' ' << val3 << ' ' << val4;
    }

    return 0;
}
