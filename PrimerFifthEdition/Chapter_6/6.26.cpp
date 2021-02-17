#include <iostream>
#include <string>

using std::cout;
using std::string;

int main(int argc, char* argv[])
{
    string str;
    for (size_t i = 1; i < argc; ++i)
    {
        str += string(argv[i]) + ' ';
    }
    cout << str;

    return 0;
}
