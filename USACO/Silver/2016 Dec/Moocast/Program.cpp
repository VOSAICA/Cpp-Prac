#include <bits/stdc++.h>
using namespace std;

struct dot
{
    int x;
    int y;
    int r;
};

int N, counter;
bool visited[200];
dot dots[200];

void dfs(int a)
{
    visited[a] = true;
    for (int i = 0; i < N; i++)
    {
        if (a == i)
            continue;
        int actuaDis = pow(dots[i].x - dots[a].x, 2) + pow(dots[i].y - dots[a].y, 2);
        if (actuaDis <= pow(dots[a].r, 2) && visited[i] == false)
        {
            counter++;
            dfs(i);
        }
    }
    return;
}

int main()
{
    ifstream fin("moocast.in");
    ofstream fout("moocast.out");
    fin >> N;
    for (int i = 0; i < N; i++)
        fin >> dots[i].x >> dots[i].y >> dots[i].r;

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        counter = 0;
        memset(visited, false, sizeof(visited));
        dfs(i);
        ans = max(ans, counter);
    }

    fout << ans + 1;
    return 0;
}
