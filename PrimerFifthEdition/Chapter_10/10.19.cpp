#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::string;
using std::vector;

void elimDups(vector<string>& nums)
{
    std::stable_sort(nums.begin(), nums.end(), [](string a, string b) { return a < b; });
    auto end_unique = std::unique(nums.begin(), nums.end());
    nums.erase(end_unique, nums.end());
}

void biggies(vector<string>& words, vector<string>::size_type sz)
{
    elimDups(words);
    std::stable_sort(words.begin(), words.end(), [](const string& a, const string& b) { return a.size() < b.size(); });

    auto wc = std::stable_partition(words.begin(), words.end(), [sz](const string& a) { return a.size() < sz; });
    auto count = words.end() - wc;
    cout << "Total: " << count << '\n';
    std::for_each(wc, words.end(), [](const string& s) { cout << s << ' '; });
}

int main()
{
    vector<string> vs{"arst", "caonim", "Gnome", "DSB", "Cretsa"};
    biggies(vs, 5);

    return 0;
}
