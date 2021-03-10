#include <algorithm>
#include <iostream>
using namespace std;

int a[100], dp[100];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    dp[0] = a[0];

    int maxValue = 0;
    for (int i = 1; i < n; i++)
    {
        dp[i] = max(a[i], dp[i - 1] + a[i]);
        if (dp[i] > maxValue)
            maxValue = dp[i];
    }

    cout << maxValue;

    return 0;
}
