#include "TextQuery.hpp"

#include <fstream>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::ifstream;
using std::string;

void find(QueryResult& qr) // do while麻烦死了
{
    do
    {
        string target;
        if (cin >> target)
        {
            auto lines = qr.find(target);
            for (auto i : lines)
            {
                cout << "LineNo: " << i << '\n';
            }
            cout << '\n';
        }
    } while (cin);
}

int main()
{
    auto ifs = ifstream("12.27_In.txt");
    TextQuery tq(ifs);
    QueryResult qr(tq);

    find(qr);

    return 0;
}
