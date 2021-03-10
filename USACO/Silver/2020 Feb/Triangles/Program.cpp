#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int n;
struct point
{
    int x;
    int y;
    vector<int> pairY;
} points[1000];

vector<int> findFarX(int a)
{
    vector<int> horizonLenS;
    for (int i = 0; i < n; i++)
    {
        if (points[i].x != points[a].x && points[i].y == points[a].y)
        {
            horizonLenS.push_back(abs(points[i].x - points[a].x));
        }
    }
    return horizonLenS;
}

bool findrep(int a, int y)
{
    vector<int>::iterator iter = find(points[a].pairY.begin(), points[a].pairY.end(), y);
    if (iter == points[a].pairY.end())
        return false;
    else
        return true;
}

int reArea(int a)
{
    vector<int> horizonLens;
    long area = 0;
    for (int i = 0; i < n; i++)
    {
        if (points[i].x == points[a].x && points[i].y != points[a].y)
        {
            // cout << points[a].x << points[a].y << " " << points[i].x << points[i].y << endl;
            points[a].pairY.push_back(points[i].y);
            int verticalLens = abs(points[i].y - points[a].y);
            horizonLens = findFarX(i);
            if (horizonLens.empty())
                break;
            for (vector<int>::iterator Xlen = horizonLens.begin(); Xlen != horizonLens.end(); Xlen++)
            {
                // cout << "Xlen: " << *Xlen << endl;
                area += verticalLens * (*Xlen);
            } // cout << endl;
        }
    }
    return area;
}

int main()
{
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> points[i].x >> points[i].y;

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += reArea(i);
    cout << ans;
    return 0;
}
