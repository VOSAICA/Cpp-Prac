#include <cctype>
#include <iostream>
#include <string>

using std::cout;
using std::string;

bool contain_caps(const string &s)
{
    bool result = false;
    for (auto i : s)
    {
        if (isupper(i))
            result = true;
    }
    return result;
}

void all_tolower(string &s)
{
    for (auto &i : s)
        i = tolower(i);
}

int main()
{
    string a{"ASS"};
    cout << contain_caps(a) << '\n';
    all_tolower(a);
    cout << contain_caps(a);

    return 0;
}
