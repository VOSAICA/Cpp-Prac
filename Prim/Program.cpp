#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;
int Edge[1000][1000];
int lowcost[100], nearvex[100];

void Prim(int u0)
{
    int sumWeight = 0;
    for (int i = 1; i <= n; i++)
    {
        lowcost[i] = Edge[u0][i];
        nearvex[i] = u0;
    }
    nearvex[u0] = -1;

    for (int i = 1; i < n; i++)
    {
        int min = 10000;
        int v = -1;
        for (int j = 1; j <= n; j++)
        {
            if (nearvex[j] != -1 && lowcost[j] < min)
            {
                v = j;
                min = lowcost[j];
            }
        }

        if (v != -1)
        {
            cout << endl;
            cout << nearvex[v] << " " << v << " " << lowcost[v] << endl;
            nearvex[v] = -1;
            sumWeight += lowcost[v];
            for (int j = 1; j <= n; j++)
            {
                if (nearvex[j] != -1 && Edge[v][j] < lowcost[j])
                {
                    lowcost[j] = Edge[v][j];
                    nearvex[j] = v;
                }
            }
        }
    }
    cout << sumWeight << endl;
}

int main()
{
    int u, v, w;
    cin >> n >> m;
    memset(Edge, 0, sizeof(Edge));
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        Edge[u][v] = Edge[v][u] = w;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                Edge[i][j] = 0;
            else if (Edge[i][j] == 0)
                Edge[i][j] = 10000;
        }
    }
    Prim(1);

    return 0;
}