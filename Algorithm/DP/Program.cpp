#include <algorithm>
#include <iostream>
using namespace std;
int f[10][10], dp[10][10];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> f[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        dp[n][i] = f[n][i];
    }

    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + f[i][j];
        }
    }

    cout << dp[1][1];

    return 0;
}
