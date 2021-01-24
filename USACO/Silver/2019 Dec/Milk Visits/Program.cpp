#include <cstdio>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
int N, M;
int comp[1000];
int num;
char col[1000];

typedef vector<int> vi;
vi adj[1000];

void dfs(int x)
{
    if (comp[x])
        return;
    comp[x] = num;
    for (vector<int>::iterator it = adj[x].begin(); it != adj[x].end(); it++)
    {
        if (col[*it] == col[x])
        {
            dfs(*it);
        }
    }
}

int main()
{
    freopen("test.in", "r", stdin);
    cin >> N >> M;
    string s;
    cin >> s;
    for (int i = 1; i < N + 1; i++)
    {
        col[i] = s[i - 1];
    }
    for (int i = 0; i < N; i++)
    {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }
    for (int i = 1; i < N + 1; i++)
    {
        if (!comp[i])
        {
            num++;
            dfs(i);
        }
    }
    for (int i = 0; i < M; i++)
    {
        int A, B;
        char C;
        cin >> A >> B >> C;
        if (col[A] == C || comp[A] != comp[B])
        {
            cout << 1;
        }
        else
            cout << 0;
    } /*
    for(int i = 1; i < N + 1; i++)
    {

    }*/

    return 0;
}
