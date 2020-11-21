#include <bits/stdc++.h>
using namespace std;

int N, M;
struct zone
{
    long long start, end;
};

vector<zone> zones;

bool cmp(zone a, zone b)
{
    return a.start < b.start;
}

bool judge(int d)
{
    int last = 0 - d - 1;
    int cows = 0;
    for (int i = 0; i < M; i++)
    {
        while (last + d <= zones[i].end)
        {
            if (zones[i].start > last + d)
            {
                last = zones[i].start - d;
            }
            last = last + d;
            cows++;
        }
    }
    if (cows < N)
        return false;
    return true;
}

int main()
{
    ifstream fin("socdist.in");
    ofstream fout("socdist.out");
    fin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        zone temp;
        fin >> temp.start >> temp.end;
        zones.push_back(temp);
    }
    sort(zones.begin(), zones.end(), cmp);

    int left = 1, right = zones[M - 1].end / (N - 2) + 1, mid;
    while (left != right)
    {
        mid = (left + right) / 2;
        if (judge(mid))
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }

    fout << mid;
    return 0;
}