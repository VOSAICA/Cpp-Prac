#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
using namespace std;

int C, N;
struct cow
{
    int start, end;
}cows[20000];

bool cmp(cow a, cow b)
{
    return a.start < b.start;
}

vector<int> chicken;

int main()
{
    ifstream fin("helpcross.in");
    fin >> C >> N;
    for (int i = 0; i < C; i++)
    {
        fin >> chicken[i];
    }
    int temp1, temp2;
    for (int i = 0; i < N; i++)
    {
        fin >> temp1 >> temp2;
        cows[i].start = temp1;
        cows[i].end = temp2;
    }

    sort(cows, cows + N, cmp);
    int ans;
    for (int i = 0; i < N; i++)
    {
        int place = chicken.lower_bound(cows[i].end);
        if (place != N && place >= cows[i].start)
        {
            ans++;
            chicken.erase(chicken[place]);
        }
    }


    return 0;
}

