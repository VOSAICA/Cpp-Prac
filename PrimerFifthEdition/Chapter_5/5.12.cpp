#include <iostream>

using std::cin;
using std::cout;

int main()
{
    char ch, last_ch;
    unsigned ffCount = 0, flCount = 0, fiCount = 0;

    while (cin >> std::noskipws >> ch) // no skip whitespace
    {
        if (last_ch == 'f')
        {
            switch (ch)
            {
            case 'f':
                ++ffCount;
                break;
            case 'l':
                ++flCount;
                break;
            case 'i':
                ++fiCount;
                break;
            }
        }
        last_ch = ch;
    }

    cout << ffCount << ' ' << flCount << ' ' << fiCount;

    return 0;
}
