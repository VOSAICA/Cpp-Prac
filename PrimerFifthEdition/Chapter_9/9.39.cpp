#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;

int main()
{
    vector<string> svec;
    svec.reserve(1024);
    string word;
    while (cin >> word)
        svec.push_back(word);
    svec.resize(svec.size() + svec.size() / 2);

    return 0;
}
