#include <deque>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::deque;
using std::string;

int main()
{
    deque<string> a;
    string temp;

    while (cin >> temp)
        a.push_back(temp);

    for (auto i = a.begin(); i != a.end(); ++i)
        cout << *i << ' ';

    return 0;
}
