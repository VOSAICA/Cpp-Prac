#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;

int main()
{
    vector<string> lst;
    string word;
    auto iter = lst.begin();
    while (cin >> word)
        iter = lst.insert(iter, word);

    for (auto i : lst)
        cout << i << ' ';

    return 0;
}
