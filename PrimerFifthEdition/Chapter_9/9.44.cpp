#include <iostream>
#include <string>

using std::cout;
using std::string;

void func(string& s, const string& oldVal, const string& newVal)
{
    for (decltype(s.size()) i = 0; i != s.size();)
    {
        if (oldVal == s.substr(i, oldVal.size()))
        {
            s.replace(i, oldVal.size(), newVal);
            i += newVal.size();
        }
        else
        {
            ++i;
        }
    }
}

int main()
{
    string s("tho thru tho th othr u");
    func(s, "tho", "though");
    func(s, "thru", "through");

    cout << s;

    return 0;
}
