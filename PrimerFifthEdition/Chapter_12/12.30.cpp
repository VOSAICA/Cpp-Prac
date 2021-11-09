#include "TextQuery2.hpp"

#include <fstream>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;

void runQueries(ifstream& infile)
{
    TextQuery tq(infile);

    while (true)
    {
        cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(cin >> s) || s == "q")
            break;
        print(cout, tq.query(s)) << endl;
    }
}

int main()
{
    ifstream ifs("12.27_In.txt");
    runQueries(ifs);

    return 0;
}
