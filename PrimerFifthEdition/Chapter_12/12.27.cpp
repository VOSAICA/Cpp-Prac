#include "TextQuery.hpp"

#include <fstream>
#include <iostream>

using std::cout;
using std::ifstream;

int main()
{
    auto ifs = ifstream("12.27_In.txt");
    TextQuery tq(ifs);

    QueryResult qr(tq);

    return 0;
}
