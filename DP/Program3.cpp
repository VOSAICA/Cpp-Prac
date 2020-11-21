#include <iostream>
#include <algorithm>
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

    int ans = -1;

    for (int i = 1; i <= n; i++)
    {
        dp[i] = 1;
        for (int j = 1; j < i; j++)
        {
            if (a[j] <= a[i] && dp[j] + 1 > dp[i])
            {
                dp[i] = dp[j] + 1;
            }
        }
        ans = max(dp[i], ans);
    }

    cout << ans;
    return 0;
}
