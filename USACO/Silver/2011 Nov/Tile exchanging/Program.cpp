#include <bits/stdc++.h>
#define MAX_M 10000
#define MAX_N 10
#define INF   1000000000
using namespace std;

int N, M, A[MAX_M + 1], best[MAX_M + 1][MAX_M + 1];

int main()
{
    ifstream fin("tilechng.in");
    ofstream fout("tilechng.out");
    fin >> N >> M;

    for (int i = 1; i <= N; i++)
        fin >> A[i];
    for (int i = 1; i <= N; i++)
        best[i][0] = INF;
    for (int i = 1; i <= M; i++)
        best[0][i] = INF;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            best[i][j] = INF;
            for (int k = 1; k * k <= j; k++)
            {
                best[i][j] = min(best[i][j], abs(A[i] - k) * abs(A[i] - k) + best[i - 1][j - k * k]);
            }
        }
    }

    if (best[N][M] == 1000000000)
        fout << -1;
    else
        fout << best[N][M];
    fout.close();
    return 0;
}
