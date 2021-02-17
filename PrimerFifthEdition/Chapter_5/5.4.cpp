#include <iostream>
#include <string>

using std::cout;
using std::string;

bool find(string word)
{
    return word == "true";
}

int main()
{
    string s("arsta");
    string ::iterator iter = s.begin();

    while (iter != s.end())
        ++iter;

    while (bool status = find("true"))
        if (!status)
            cout << "false";
        else
        {
            cout << "true";
            break;
        }

    return 0;
}
