#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

int main()
{
    string s, last_s{};
    bool flag = false;

    while (cin >> s)
    {
        if (s == last_s)
        {
            flag = true;
            break;
        }
        last_s = s;
    }

    cout << (flag ? "\0" : "No repetition");

    return 0;
}
