#include <iostream>

using std::cout;

int main()
{
    int x = 1, y = 2;
    bool someValue = false;

    someValue ? ++x, ++y : --x, --y;
    //等价(someValue ? ++x, ++y : --x), --y; y最后都要自减
    cout << x << ' ' << y;

    return 0;
}
