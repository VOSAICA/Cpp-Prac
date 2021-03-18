#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::string;
using std::vector;

int main()
{
    vector<char> a{'H', 'e', 'l', 'l', 'o'};
    string s(a.cbegin(), a.cend());
    cout << s;

    return 0;
}
