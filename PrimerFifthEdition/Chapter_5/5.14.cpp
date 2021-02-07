#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;

int main()
{
    string cur_str, last_str{};
    vector<string> str;
    vector<unsigned> count;

    unsigned str_count = 1;

    while (cin >> cur_str)
    {
        if (cur_str == last_str)
            ++str_count;
        else
        {
            str.emplace_back(last_str);
            count.emplace_back(str_count);
            str_count = 1;
        }
        last_str = cur_str;
    }

    decltype(count.size()) index_max = 0;
    unsigned max = 0;
    for (decltype(count.size()) i = 0; i != count.size(); ++i)
        if (count[i] > max)
            index_max = i, max = count[i];

    if (max == 1)
        cout << "No repetition";
    else
        cout << str[index_max] << ": " << max;

    return 0;
}
