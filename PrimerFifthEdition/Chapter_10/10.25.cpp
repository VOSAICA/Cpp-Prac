#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std::placeholders;

using std::bind;
using std::cout;
using std::string;
using std::vector;

bool check_size(const string& s, string::size_type sz)
{
    return s.size() < sz;
}

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

    auto wc = std::stable_partition(words.begin(), words.end(), bind(check_size, _1, sz));
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
