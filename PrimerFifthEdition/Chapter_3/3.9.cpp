#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main()
{
    string s;
    cout << s[0] << endl;

    return 0;
}
//可以过编译，但s未初始化，s[0]为未定义值
