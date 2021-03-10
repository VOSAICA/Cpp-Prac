#include <fstream>
#include <iostream>
using namespace std;

struct cow
{
    int nums[19];
} cows[21];

int main()
{
    int k, n; // k:traing times, n: cows
    int a[10][20];
    int temp[19];
    ifstream fin;
    fin.open("gymnastics.in");
    fin >> k >> n;

    for (int j = 0; j < k; j++)
    {
        for (int i = 0; i < n; i++)
        {
            fin >> a[j][i];
            cout << a[j][i];
        }
        cout << endl;
    }

    for (int k = 1; k < n + 1; k++)
    {
        int place = 0;
        for (int j = 0; j < k; j++)
        {
            for (int i = 0; i < n; i++)
            {
                if (a[j][i] == k)
                {
                    for (int x = i; x > 0; x--)
                    {
                        for (int c = 0; c < n - 1; c++)
                        {
                            if (a[j][x] != temp[c])
                                continue;
                            else
                                break;
                        }
                        temp[place] = a[j][x];
                        place++;
                    }
                }
            }
        }
        for (int i = 0; i < place + 1; i++)
    }

    return 0;
}
