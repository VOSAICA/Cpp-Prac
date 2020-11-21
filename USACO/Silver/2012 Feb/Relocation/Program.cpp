#include <bits/stdc++.h>
#define Inf 0x3f3f3f3f

using namespace std;

int towns[1005][1005];

int vis[1005], dis[1005];
int N, M, K; //n个点，m条边
int markets[5];

void Dijkstra(int u)
{
    memset(towns, Inf, sizeof(towns));
    for (int i = 1; i <= N; i++)
    {
        towns[i][i] = 0;
    }
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i <= N; i++)
    {
        dis[i] = towns[u][i];
    }
    vis[u] = 1;

    for (int t = 0; t < N; t++)
    {
        int minn = Inf, temp;
        for (int i = 1; i <= N; i++)
        {
            if (!vis[i] && dis[i] < minn)
            {
                minn = dis[i];
                temp = i;
            }
        }
        vis[temp] = 1;

        for (int i = 1; i <= N; i++)
        {
            if (towns[temp][i] + dis[temp] < dis[i])
            {
                dis[i] = towns[temp][i] + dis[temp];
            }
        }
    }
}

int main()
{
    ifstream fin("relocat.in");
    ofstream fout("relocate.out");
    int u, v, w;
    for (int t = 1; t <= M; t++)
    {
        cin >> u >> v >> w;
        if (towns[u][v] > w)
        {
            towns[u][v] = w;
            towns[v][u] = w;
        }
    }
}