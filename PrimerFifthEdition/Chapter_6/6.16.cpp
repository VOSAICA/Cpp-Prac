#include <iostream>
#include <string>

using std::cout;
using std::string;

bool is_empty(const string &s) { return s.empty(); }

int main()
{
    cout << is_empty("arst");

    return 0;
}
