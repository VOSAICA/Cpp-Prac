#include <iostream>
#include <string>

using std::cout;
using std::string;

int main()
{
    string s = "word";
    string pl = s + (s[s.size() - 1] == 's' ? "" : "s"); //没有括号就会先算+，然后拿string跟's'比较

    cout << pl;

    return 0;
}
