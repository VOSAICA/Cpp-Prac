#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using std::cout;
using std::ifstream;
using std::string;
using std::vector;

int main()
{
    ifstream ifs("10.29_In.txt");
    std::istream_iterator<string> ists(ifs), eof;

    vector<string> vstr(ists, eof);

    for (auto i : vstr)
        cout << i << '\n';

    return 0;
}
