#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::getline;
using std::string;

int main()
{
    string a, b;
    cin >> a;        //忽略开头的空白（空格符、换行符、制表符……），从第一的字符读起，直到下一个空白
    getline(cin, b); //读取一整行直到换行符

    cout << a + '\n' + b;

    return 0;
}
