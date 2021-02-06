#include <iostream>

using std::cout;

int main()
{
    int sum = 0, val = 0;
    while (val <= 10)
        sum += val, ++val;

    cout << sum;

    return 0;
}
