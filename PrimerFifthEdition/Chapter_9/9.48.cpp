#include <iostream>
#include <string>

using std::cout;
using std::string;

int main()
{
    string name("AnnaBelle");
    string numbers("0123456789");

    cout << numbers.find(name); // 返回string::npos

    return 0;
}
