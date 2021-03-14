#include <iostream>
#include <list>
#include <string>

using std::cin;
using std::cout;
using std::list;
using std::string;

int main()
{
    list<string> a;
    string temp;

    while (cin >> temp)
        a.push_back(temp);

    for (auto i = a.begin(); i != a.end(); ++i)
        cout << *i << ' ';

    return 0;
}
