#include <bits/stdc++.h>
using namespace std;

int N, Q, matrix[5001][5001];

int fas(int k, int node)
{
    int counter = 0;
    for (int i = 1; i <= N; i++)
    {
        if (matrix[node][i] >= k)
        {
            counter++;
        }
    }
    return counter;
}

void floyd()
{
    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (i == j)
                    continue;
                if (matrix[i][j] == 0)
                {
                    matrix[i][j] = matrix[j][i] = min(matrix[i][k], matrix[k][j]);
                }
            }
        }
    }
}

int main()
{
    ifstream fin("mootube.in");
    ofstream fout("mootube.out");
    fin >> N >> Q;

    int x, y, w, k, node;
    for (int i = 0; i < Q; i++)
    {
        fin >> x >> y >> w;
        matrix[x][y] = matrix[y][x] = w;
    }

    floyd();

    for (int i = 0; i < Q; i++)
    {
        fin >> k >> node;
        if (i == Q - 1)
        {
            fout << fas(k, node);
            break;
        }
        fout << fas(k, node) << endl;
    }
}
