#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;

int main()
{
    vector<string> v;
    string a;
    while (getline(cin, a))
        v.emplace_back(a);

    auto it = v.begin();
    for (auto it2 = it->begin(); it2 != it->end(); ++it2)
    {
        *it2 = toupper(*it2);
    }
    cout << *it;

    return 0;
}
