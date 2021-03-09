#include <cstring>
#include <iostream>
using namespace std;

int n, s, l;
struct snakeAndLadder
{
    int from, to;
};

int main()
{
    int grid[1000];
    int bakgrid[1000];
    int deal;
    int step = 0;
    cin >> n >> s >> l;
    snakeAndLadder obstacle[100];
    for (int i = 0; i < s + l; i++)
    {
        cin >> obstacle[i].from;
        cin >> obstacle[i].to;
    }
    memset(grid, 0, sizeof(grid));
    grid[1] = 1;

    while (grid[n * n] == 0)
    {
        memcpy(bakgrid, grid, sizeof(grid));
        memset(grid, 0, sizeof(grid));
        for (int i = 1; i < n * n; i++)
        {
            if (bakgrid[i] == 0)
                continue;
            for (int k = 1; k <= 6; k++)
            {
                deal = 0;
                if (k + i > n * n)
                    break;
                for (int j = 0; j < s + l; j++)
                {
                    if (obstacle[j].from == i + k)
                    {
                        grid[obstacle[j].to] = 1;
                        deal = 1;
                        break;
                    }
                }
                if (deal == 0 && grid[i + k] == 0)
                {
                    grid[i + k] = 1;
                }
            }
        }
        step++;
    }
    cout << step;

    return 0;
}
