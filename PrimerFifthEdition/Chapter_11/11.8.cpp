#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;

int main()
{
    vector<string> words;
    string word;

    while (cin >> word)
    {
        bool exist = false;
        for (auto i : words)
        {
            if (i == word)
            {
                exist = true;
                break;
            }
        }
        if (exist == false)
            words.emplace_back(word);
    }

    for (auto i : words)
        cout << i << ' ';

    return 0;
}
// set比较快
