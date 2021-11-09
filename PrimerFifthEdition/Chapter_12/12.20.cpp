#include "StrBlob.h"

#include <fstream>
#include <iostream>
#include <string>

using std::cout;
using std::getline;
using std::ifstream;
using std::string;

int main()
{
    ifstream ifs("12.20_In.txt");
    StrBlob a;
    string temp;
    while (getline(ifs, temp))
    {
        a.push_back(temp);
    }

    for (auto st = a.begin(); st != a.end(); st.incr())
    {
        cout << st.deref() << ' ';
    }

    return 0;
}
// g++ 12.20.cpp StrBlob.cpp -o 12.20.exe
