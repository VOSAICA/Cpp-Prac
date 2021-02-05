#include <iostream>

using std::cout;

int main()
{
    int i = 7;
    double d = 8.0;

    cout << (i *= static_cast<int>(d));

    return 0;
}
