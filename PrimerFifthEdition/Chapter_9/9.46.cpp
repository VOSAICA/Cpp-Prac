#include <iostream>
#include <string>

using std::cout;
using std::string;

string func(const string& s, const string& prefix, const string& suffix)
{
    string r(s);
    decltype(r.size()) i = 0;
    r.insert(i, prefix);
    r.insert(r.size(), suffix);

    return r;
}

int main()
{
    cout << func("Alice", "Ms. ", " Jr.");

    return 0;
}
