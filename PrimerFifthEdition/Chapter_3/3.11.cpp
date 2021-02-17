#include <iostream>
#include <string>

using std::string;

int main()
{
    const string s = "Keep out!";
    for (auto& c : s)
    {
        // const char &c
    }

    return 0;
}
