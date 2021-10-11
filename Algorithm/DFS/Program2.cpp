#include <iostream>
using namespace std;

char map[9][9];
int n, m;
int dir[8][2] = {
    { 0, -1},
    { 0,  1},
    { 1,  0},
    {-1,  0},
    {-1, -1},
    { 1,  1},
    {-1,  1},
    { 1, -1}
};

void dfs(int x, int y)
{
    int xx, yy;

    map[x][y] = '*';
    for (int i = 0; i < 8; i++)
    {
        xx = x + dir[i][0];
        yy = y + dir[i][1];
        if (xx < 0 || yy < 0 || xx > n || yy > m)
            continue;
        if (map[xx][yy] == '@')
        {
            dfs(xx, yy);
        }
    }
}

int main()
{
    cin >> m >> n;
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] == '@')
            {
                dfs(i, j);
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}
