#include <iostream>
#include <string>

using std::cout;
using std::string;

void func(string& s, const string& oldVal, const string& newVal)
{
    for (auto iter = s.begin(); iter != s.end();)
    {
        if (oldVal == string(iter, iter + oldVal.size()))
        {
            iter = s.erase(iter, iter + oldVal.size());
            iter = s.insert(iter, newVal.begin(), newVal.end());
            iter += newVal.size();
        }
        else
        {
            ++iter;
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
