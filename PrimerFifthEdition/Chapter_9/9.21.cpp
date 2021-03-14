#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::vector;
using std::string;

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
