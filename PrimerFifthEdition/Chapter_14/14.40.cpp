#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::string;
using std::vector;

struct Smaller
{
    bool operator()(const string& a, const string& b)
    {
        return a < b;
    }
};

void elimDups(vector<string>& nums)
{
    std::stable_sort(nums.begin(), nums.end(), Smaller());
    auto end_unique = std::unique(nums.begin(), nums.end());
    nums.erase(end_unique, nums.end());
}

void biggies(vector<string>& words, vector<string>::size_type sz)
{
    elimDups(words);
    std::stable_sort(words.begin(), words.end(), Smaller());

    auto wc = std::partition(words.begin(), words.end(), [sz](const string& a) { return a.size() < sz; });
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
