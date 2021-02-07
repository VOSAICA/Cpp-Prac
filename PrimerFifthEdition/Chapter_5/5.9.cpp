#include <iostream>

using std::cin;
using std::cout;

int main()
{
    char ch;
    unsigned count = 0;

    while (cin >> ch)
    {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            ++count;
    }

    cout << count;

    return 0;
}
