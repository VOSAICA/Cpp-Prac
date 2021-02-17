#include <iostream>

using std::cin;
using std::cout;

int main()
{
    char ch;
    unsigned vowelCount = 0;
    unsigned enterCount = 0;
    unsigned spaceCount = 0;
    unsigned tabCount = 0;

    while (cin >> std::noskipws >> ch) // no skip whitespace
    {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            ++vowelCount;
        else if (ch == '\n')
            ++enterCount;
        else if (ch == ' ')
            ++spaceCount;
        else if (ch == '\t')
            ++tabCount;
    }

    cout << vowelCount << ' ' << enterCount << ' ' << spaceCount << ' ' << tabCount;
    cout << '\t';
    cout << 'a';

    return 0;
}
