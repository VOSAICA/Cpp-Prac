#include <iostream>

using std::cout;
using std::endl;

int get_value()
{
    return 5;
}

int main()
{
    int ival = 5, ival1 = 1, ival2 = 1, minval = 10;
    int occurs = 0;

    if (ival1 != ival2)
        ival1 = ival2;
    else
        ival1 = ival2 = 0;

    if (ival < minval)
        minval = ival, occurs = 1;

    if (int ival == get_value())
        cout << "ival = " << ival << endl;
    else if (!ival)
        cout << "ival = 0\n";

    if (ival == 0)
        ival = get_value();

    return 0;
}
