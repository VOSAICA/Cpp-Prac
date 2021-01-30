#include <cstring>
#include <iostream>
using std::cout;
using std::endl;

int main()
{
    const char ca[] = {'h', 'e', 'l', 'l', 'o'}; //C风格字符串应该以空字符\0结尾
    const char *cp = ca;

    while (*cp)
    {
        cout << *cp << endl;
        ++cp;
    }
    cout << strlen(ca); //ca没有以空字符结尾，会有错误

    return 0;
}
