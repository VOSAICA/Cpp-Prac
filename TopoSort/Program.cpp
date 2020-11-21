#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> G[101];
int n, m;
int inDegree[101];

void topoSort()
{
    int num = 0;
    queue<int> q;
    for (int i = 1; i < n + 1; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int u = q.front();
        cout << u;
        q.pop();
        for (int i = 0; i < G[u].size(); i++)
        {
            int v = G[u][i];
            inDegree[v]--;
            if (inDegree[v] == 0)
            {
                q.push(v);
            }
        }
        G[u].clear();
        num++;
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int A, B;
        cin >> A >> B;
        G[A].push_back(B);
        inDegree[B]++;
    }
    topoSort();

    return 0;
}
