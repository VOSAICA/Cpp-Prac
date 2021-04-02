#include "Sales_item.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

using std::cerr;
using std::cin;
using std::cout;
using std::vector;

bool smallerIsbn(const Sales_item& a, const Sales_item& b)
{
    return a.isbn() < b.isbn();
}

int main()
{
    Sales_item total;
    std::istream_iterator<Sales_item> isIter(cin), eof;
    std::ostream_iterator<Sales_item> osIter(cout, " ");

    vector<Sales_item> record(isIter, eof);
    std::sort(record.begin(), record.end(), smallerIsbn);

    for (decltype(record.begin()) curIter = record.begin(); curIter != record.end(); ++curIter)
    {
        auto index = std::find_if(
            curIter, record.end(), [curIter](const Sales_item& member) { return member.isbn() != curIter->isbn(); });
        *osIter++ = std::accumulate(curIter, index, Sales_item(curIter->isbn()));
        curIter = --index;
    }

    return 0;
}
