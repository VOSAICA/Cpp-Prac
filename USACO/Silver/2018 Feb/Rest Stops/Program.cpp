#include <algorithm>
#include <fstream>
#include <iostream>
using namespace std;

int n;
int l;
int rB, rF;

struct rest
{
    int dis;
    int c;
} rests[100000];

bool compare(rest a, rest b)
{
    return a.c > b.c;
}

int main()
{
    ifstream fin;
    fin.open("reststops.in");
    fin >> l >> n >> rF >> rB;

    for (int i = 0; i < n; i++)
    {
        fin >> rests[i].dis;
        fin >> rests[i].c;
    }
    sort(rests, rests + n, compare);

    int far = 0;
    int timespan = 0;
    int satis = 0;
    for (int i = 0; i < n; i++)
    {
        if (rests[i].dis > far)
        {
            far = rests[i].dis;
            if (rB * rests[i].dis + timespan <= rF * rests[i].dis)
            {
                satis += (rests[i].dis * (rF - rB) - timespan) * rests[i].c;
                timespan = rests[i].dis * (rF - rB);
            }
        }
    }

    ofstream fout;
    fout.open("restops.out");
    fout << satis;

    return 0;
}