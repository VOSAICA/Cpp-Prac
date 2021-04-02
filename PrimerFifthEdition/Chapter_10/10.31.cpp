#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

int main()
{
    std::istream_iterator<int> itercin(cin), eof;
    vector<int> vin(itercin, eof);
    std::sort(vin.begin(), vin.end());

    std::ostream_iterator<int> itercout(cout, " ");
    std::unique_copy(vin.begin(), vin.end(), itercout);

    return 0;
}
