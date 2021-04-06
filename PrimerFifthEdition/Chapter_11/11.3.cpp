#include <iostream>
#include <map>
#include <string>

using std::cin;
using std::cout;
using std::map;
using std::string;

int main()
{
    map<string, long long> word_count;
    string word;

    while (cin >> word)
        ++word_count[word];
    for (const auto& w : word_count)
        cout << w.first << ": " << w.second << '\n';

    return 0;
}
