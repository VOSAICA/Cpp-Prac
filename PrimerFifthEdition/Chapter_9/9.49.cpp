#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::ifstream;
using std::string;
using std::vector;

int main()
{
    ifstream ifs("9.49_Letters.txt");
    string str, longest;
    vector<char> forbidden{'d', 'f', 'p', 'g', 'j', 'k', 'q', 'b', 'h', 'i', 'y', 'l'};
    while (ifs >> str)
    {
        bool ok = true;
        for (auto i : forbidden)
        {
            if (str.find(i) != string::npos)
                ok = false;
        }
        if (ok and str.size() > longest.size())
            longest = str;
    }
    ifs.close();

    cout << longest;

    return 0;
}
