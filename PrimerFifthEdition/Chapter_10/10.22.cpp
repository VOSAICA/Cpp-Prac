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
    return s.size() >= sz;
}

int main()
{
    vector<string> vs{"arst", "caonim", "Gnome", "DSB", "Cretsa", "Vethodology"};
    cout << std::count_if(vs.begin(), vs.end(), bind(check_size, _1, 6));

    return 0;
}
