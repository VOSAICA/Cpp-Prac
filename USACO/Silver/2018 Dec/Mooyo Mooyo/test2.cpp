#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;

char grid[100][10];
int N, K;
void refresh(int i, int j)
{
    if (grid[i][j] == '0')
    {
        for (int k = i; k >= 0; k--)
        {
            if (grid[k][j] != '0')
            {
                grid[i][j] = grid[k][j];
                grid[k][j] = '0';
                break;
            }
        }
    }
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

    for (int i = N - 1; i >= 0; i--)
    {
        for (int j = 0; j < 10; j++)
        {
            refresh(i, j);
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    // cout << grid[i][j];
                }
                // cout << endl;
            }
            // cout << endl << endl;
        }
    }

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
