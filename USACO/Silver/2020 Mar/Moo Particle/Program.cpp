#include <bits/stdc++.h>
using namespace std;

struct particle
{
    int x, y;
};

bool cmp(particle a, particle b)
{
    if (a.x == b.x)
    {
        return a.y < b.y;
    }
    else
    {
        return a.x < b.x;
    }
}

vector<particle> toRight, toLeft;
int N;

int react()
{
    int last;
    while (i <= toRight.size())
    {
        int i = 0;
        if (toRight[i].x == toRight[last].x && toRight[i].y == toRight[i].y)
            i++;
        last = i;
        for (int j = toRight.size() - 1; j >= 0; j++)
        {
            if (j == i)
                continue;
            if (toRight[i].x >= toRight[j].x && toRight[i].y >= toRight[j].y)
            {
                toRight.erase(toRight.begin() + j);
            }
        }
    }

    for (int i = particles.size() - 2; i >= 0; i--)
    {
        if (particles[particles.size() - 1].x >= particles[i].x && particles[particles.size() - 1].y >= particles[i].y)
        {
            particles.erase(particles.begin() + i);
            continue;
        }
    }

    return toLeft.size() + toRight.size();
}

int main()
{
    ifstream fin("moop.in");
    ofstream fout("moop.out");
    fin >> N;

    particle a;
    for (int i = 0; i < N; i++)
    {
        fin >> a.x >> a.y;
        if (a.x > a.y)
        {
            toLeft.push_back(a);
        }
        else
        {
            toRight.push_back(a);
        }
    }

    fout << react();
    return 0;
}
