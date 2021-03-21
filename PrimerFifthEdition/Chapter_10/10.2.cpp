#include <algorithm>
#include <iostream>
#include <list>
#include <string>

using std::cout;
using std::list;
using std::string;

int main()
{
    list<string> lstr{"arst", "arst", "aosrtyu", "arysth"};
    cout << std::count(lstr.cbegin(), lstr.cend(), "arst");

    return 0;
}
