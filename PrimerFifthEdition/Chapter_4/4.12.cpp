#include <iostream>

using std::cin;
using std::cout;

int main()
{
    int i = 0, j = 3, k = 5;

    cin >> i >> j >> k;
    if (i != j < k) // i != (j < k)
        cout << "True";
    else
        cout << "False";

    return 0;
}
