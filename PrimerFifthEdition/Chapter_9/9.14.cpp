#include <cstring>
#include <iostream>
#include <list>
#include <string>
#include <vector>

using std::cout;
using std::list;
using std::string;
using std::vector;

int main()
{
    const char cs1[] = "UR";
    const char cs2[] = "SB";

    list<const char*> a{cs1, cs2};

    vector<string> b;
    b.assign(a.begin(), a.end());

    for (auto i : b)
        cout << i << ' ';

    return 0;
}
