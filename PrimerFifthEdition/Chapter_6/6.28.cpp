#include <initializer_list>
#include <iostream>
#include <string>

using std::cout;
using std::initializer_list;
using std::string;

struct ErrCode
{
    string msg;
};

void error_msg(ErrCode e, std::initializer_list<string> il)
{
    cout << e.msg << ": ";
    for (const auto& elem : il) // const string &
        cout << elem << " ";
    cout << '\n';
}

int main()
{

    return 0;
}
