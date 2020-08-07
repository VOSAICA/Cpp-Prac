#include<iostream>
using namespace std;

int main()
{
    int a[1000][1000];

    int n, m;
    int x, y;
    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        cin >> x >> y;
        a[x - 1][y - 1] = 1;
    }

    for(int i = 0; i < n; i++)
    {
        int out = 0;
        for(int j = 0; j < n; j++)
        {
            if(a[i][j] == 1) out += 1;
        }
        cout << out;
    }
    cout << endl;

    for(int i = 0; i < n; i++)
    {
        int in = 0;
        for(int j = 0; j < n; j++)
        {
            if(a[j][i] == 1) in += 1;
        }
        cout << in;
    }
    cout << endl;

    return 0;
}
