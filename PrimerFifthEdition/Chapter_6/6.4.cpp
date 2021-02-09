#include <iostream>

using std::cin;
using std::cout;

int fact(int n)
{
    if (n == 1)
        return 1;
    return n * fact(n - 1);
}

void input()
{
    cout << "Input a number: ";
    int n;
    cin >> n;
    cout << fact(n);
}

int main()
{
    input();

    return 0;
}
