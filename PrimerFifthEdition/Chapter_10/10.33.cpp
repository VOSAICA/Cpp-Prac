#include "Sales_item.h"
#include <fstream>
#include <iterator>
#include <string>

using std::ifstream;
using std::ofstream;
using std::string;

int main(int argc, char* argv[])
{
    ifstream inf(argv[1]);
    ofstream odd(argv[2]);
    ofstream even(argv[3]);

    std::istream_iterator<int> isIter(inf), eof;
    std::ostream_iterator<int> oddOfIter(odd, " ");
    std::ostream_iterator<int> evenOfIter(even, " ");

    while (isIter != eof)
    {
        int temp = *isIter++;
        if (temp % 2 == 0)
            oddOfIter = temp;
        else
            evenOfIter = temp;
    }

    return 0;
}
// ./10.33.exe 10.33_In.txt 10.33_Odd.txt 10.33_Even.txt
