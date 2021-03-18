#include <iostream>
#include <string>

using std::cout;
using std::string;

string func(const string& s, const string& prefix, const string& suffix)
{
    string r(s);
    auto iter = r.begin();
    r.insert(iter, prefix.begin(), prefix.end());
    r.append(suffix);

    return r;
}

int main()
{
    cout << func("Alice", "Ms. ", " Jr.");

    return 0;
}
