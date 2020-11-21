#include <iostream>
using namespace std;

char map[9][9];
int n, m, t;
int di, dj;
bool escape;
int dir[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

void dfs(int si, int sj, int cnt)
{
	if (si < 0 || si > n || sj < 0 || sj > m)
		return;
	if (si == di && sj == dj && cnt == t)
		escape = true;

	int temp = cnt - abs(si - di) - abs(sj - dj);
	if (temp < 0 || temp % 2)
		return;

	for (int i = 0; i < 4; i++)
	{
		if (map[si + dir[i][0]][sj + dir[i][1]] != 'X')
		{
			map[si + dir[i][0]][sj + dir[i][1]] = 'X';
			dfs(si + dir[i][0], sj + dir[i][1], cnt + 1);
			if (escape)
				return;
			map[si + dir[i][0]][sj + dir[i][1]] = '.';
		}
	}
}

int main()
{
	int wall = 0;
	int si, sj;
	cin >> n >> m >> t;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'X')
				wall++;
			else if (map[i][j] == 'S')
			{
				si = i;
				sj = j;
			}
			else if (map[i][j] == 'D')
			{
				di = i;
				dj = j;
			}
		}
	}
	if (n * m - wall <= t)
	{
		cout << "NO" << endl;
	}
	map[si][sj] = 'X';
	dfs(si, sj, 0);
	if (escape)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}

	return 0;
}
