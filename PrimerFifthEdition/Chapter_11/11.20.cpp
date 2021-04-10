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
        ++word_count.insert({word, 0}).first->second; // insert().first是具有给定关键字的元素的迭代器

    for (const auto& w : word_count)
        cout << w.first << ": " << w.second << '\n';

    return 0;
}
// 还是11.3好读点
