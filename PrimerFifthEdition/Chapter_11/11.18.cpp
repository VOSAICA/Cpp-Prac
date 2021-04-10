#include <iostream>
#include <map>
#include <string>

using std::cout;
using std::map;
using std::string;

int main()
{
    map<string, size_t> word_count;
    auto map_it = word_count.cbegin(); // map<string, size_t>::const_iterator

    return 0;
}
