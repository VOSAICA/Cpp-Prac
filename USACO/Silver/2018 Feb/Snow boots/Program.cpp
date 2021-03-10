#include <bits/stdc++.h>
using namespace std;

int N, B;
int deepth[251], length[251], road[1001], reach[1001][251];

int solve()
{
    for (int i = 1; i <= B; i++)
    {
        reach[i][1] = true;
        for (int j = 1; j <= N; j++)
        {
            if (road[j] > deepth[i])
                continue;

            for (int k = max(1, j - length[i]); k < j; k++)
                if (reach[i][k] == true)
                {
                    reach[i][j] = true;
                    break;
                }
            if (i > 1 && reach[i - 1][j] == true)
                reach[i][j] = true;

            if (j == N && reach[i][j] == true)
                return i - 1;
        }
    }
    return -1;
}

int main()
{
    ifstream fin("snowboots.in");
    ofstream fout("snowboots.out");
    fin >> N >> B;
    for (int i = 1; i <= N; i++)
        fin >> road[i];
    for (int i = 1; i <= B; i++)
        fin >> deepth[i] >> length[i];

    fout << solve();
    return 0;
}
