#include<bits/stdc++.h>
using namespace std;
int A, B, N;
float cow[2001];
float dp[2001];

int solve()
{
    dp[0] = 0;
    for (int i = 1; i <= N; i++)
    {
        dp[i] = 1000000.0;
        for (int j = 0; j < i; j++)
        {
            float r = (cow[i] - cow[j + 1]) / 2;
            dp[i] = min(dp[i], dp[j] + A + r * B);
        }
    }
    return dp[N];
}

int main()
{
    ifstream fin("wifi.in");
    ofstream fout("wifi.out");
    fin >> N >> A >> B;
    for (int i = 1; i <= N; i++)
    {
        fin >> cow[i];
    }
    sort(cow, cow + N);
    
    fout << solve();
    return 0;
}
