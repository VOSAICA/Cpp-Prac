#include <algorithm>
#include <iostream>
using namespace std;

int N, M;
int parent[51];

struct edge
{
    int u;
    int v;
    int w;
} edges[51];

void UFset()
{
    for (int i = 0; i < N; i++)
    {
        parent[i] = -1;
    }
}
bool compare(edge a, edge b)
{
    return a.w < b.w;
}

int find(int x)
{
    int s;
    for (s = x; parent[s] >= 0; s = parent[s])
        ;
    while (s != x)
    {
        int tmp;
        tmp = parent[x];
        parent[x] = s;
        x = tmp;
    }
    return s;
}

void Union(int R1, int R2)
{
    int r1 = find(R1);
    int r2 = find(R2);
    int tmp = parent[r1] + parent[r2];
    if (parent[r1] > parent[r2])
    {
        parent[r1] = r2;
        parent[r2] = tmp;
    }
    else
    {
        parent[r2] = r1;
        parent[r1] = tmp;
    }
}

void Kruskal()
{
    int sumWeight = 0;
    int edgeNum = 0;
    int u, v, w;
    UFset();
    cout << "y";
    for (int i = 0; i < M; i++)
    {
        u = edges[i].u;
        v = edges[i].v;
        w = edges[i].w;
        cout << find(u) << " " << find(v) << endl;
        if (find(u) != find(v))
        {
            cout << u << " " << v << " " << w << endl;
            sumWeight += w;
            Union(u, v);
            edgeNum++;
        }
        if (edgeNum >= N - 1)
            break;
    }
    cout << "SumWeight: " << sumWeight << endl;
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    sort(edges, edges + M, compare);
    cout << " x";
    Kruskal();
}