#include <bits/stdc++.h>
using namespace std;

int N, T;
vector<int> cows;

bool check(int stageSize)
{
    priority_queue<int, vector<int>, greater<int>> stage;
    int last = 0;
    for (int i = 0; i < N; i++)
    {
        if (stage.size() == stageSize)
        {
            last = stage.top();
            stage.pop();
        }
        if (last + cows[i] > T)
        {
            return false;
        }
        stage.push(cows[i] + last);
    }
    return true;
}

int main()
{
    ifstream fin("cowdance.in");
    ofstream fout("cowdance.out");
    fin >> N >> T;

    int temp;
    for (int i = 0; i < N; i++)
    {
        fin >> temp;
        cows.push_back(temp);
    }

    int left = 1, right = N, stageSize;
    while (left != right)
    {
        stageSize = (left + right) / 2;
        if (check(stageSize))
        {
            right = stageSize;
        }
        else
        {
            left = stageSize + 1;
        }
    }

    fout << stageSize;
    fout.close();
    return 0;
}