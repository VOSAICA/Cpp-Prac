#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;

int N = 6, K = 3;
int si, sj;
int grid[100][10];
int been[100][10];
int dir[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
int enough;

void Dfs(int si, int sj)
{
	int xi, xj;
	int temp = grid[si][sj];
	been[si][sj] = 1;
	if (si < 0 || si > N - 1 || sj < 0 || sj > 9)
		return;
	for (int i = 0; i < 4; i++)
	{
		xi = si + dir[i][0];
		xj = sj + dir[i][1];
		if (grid[xi][xj] == temp && been[xi][xj] == 0)
		{
			enough++;
			Dfs(xi, xj);
		}
	}
	if (enough >= K)
		grid[si][sj] = 0;
	else
		grid[si][sj] = temp;
}

int main()
{
	ifstream fin;
	fin.open("mooyomooyo.in");
	fin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			fin >> grid[i][j];
		}
	}

	//enough = 1;
	//Dfs(5, 0);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << grid[i][j];
		}
		cout << endl;
	}

	return 0;
}
