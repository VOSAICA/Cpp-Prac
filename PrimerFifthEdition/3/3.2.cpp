#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string line;
    std::getline(cin, line);
    cout << line + '\n';

    string word;
    cin >> word;
    cout << word << endl;

    return 0;
}
