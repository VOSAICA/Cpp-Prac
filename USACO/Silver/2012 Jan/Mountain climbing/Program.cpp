#include <bits/stdc++.h>
using namespace std;

int N;
struct climb
{
    int up, down;
} cows[25000];

bool cmp(climb a, climb b)
{
    if (a.up < a.down)
    {
        if (b.up < b.down)
            return a.up > b.up;
        else
            return true;
    }
    else
    {
        if (b.up > b.up)
            return a.down > b.down;
        else
            return true;
    }
}

int main()
{
    ifstream fin("climb.in");
    ofstream fout("climb.out");

    for (int i = 0; i < N; i++)
    {
        fin >> cows[i].up >> cows[i].down;
    }

    sort(cows, cows + N, cmp);

    for (int i = 0; i < N; i++)
    {
    }

    fout.close();
    return 0;
}