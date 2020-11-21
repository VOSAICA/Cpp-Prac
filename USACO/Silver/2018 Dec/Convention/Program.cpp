#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
    int n, m, c;
    ifstream fin;
    fin.open("convention.in");
    fin >> n >> m >> c;
    int a[100][100], b[100];

    for (int i = 0; i < n; i++)
    {
        fin >> b[i];
    }
    sort(b, b + n);

    int p = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < c; j++)
        {
            a[i][j] = b[p];
            p++;
            cout << a[i][j];
        }
    }

    int max = 0;
    for (int i = 0; i < m; i++)
    {
        int diff = a[i][c - 1] - a[i][0];
        if (diff > max)
            max = diff;
    }
    cout << max;

    return 0;
}
