#include <iostream>

using std::cout;

int main()
{
    int ival = 0;
    char cval = 'a';

    if (ival == 1)
        if (cval != 'a')
            cout << "SB";
    else
        cout << "SBB";

/*其实是
    if (ival == 1)
        if (cval != 'a')
            cout << "SB";
        else
            cout << "SBB";
 */

    return 0;
}
