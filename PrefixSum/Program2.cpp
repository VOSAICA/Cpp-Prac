#include <iostream>
#include <algorithm>
using namespace std;

int grid[100][100];
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        grid[a][b]++;
        grid[a][d]--;
        grid[c][b]--;
        grid[c][d]++;
    }
    int ret = 0;
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (i)
                grid[i][j] += grid[i - 1][j];
            if (j)
                grid[i][j] += grid[i][j - 1];
            if (i && j)
                grid[i][j] -= grid[i - 1][j - 1];
            if (grid[i][j] == k)
                ret++;
        }
    }

    cout << ret;
    return 0;
}