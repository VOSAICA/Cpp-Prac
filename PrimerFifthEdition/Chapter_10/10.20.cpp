#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::string;
using std::vector;

int main()
{
    vector<string> vs{"arst", "caonim", "Gnome", "DSB", "Cretsa", "Vethodology"};
    cout << std::count_if(vs.begin(), vs.end(), [](string a) { return a.size() > 6; });

    return 0;
}
