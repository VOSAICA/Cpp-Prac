#include<iostream>
#include <cstdio>
#include <cstdlib>
#include<vector>
#include<algorithm>
using namespace std;

struct Edge{
    int d, w;
};

int n, m;
int* loc;
int* component;
vector<Edge>* edges;


void dfs(int curr, int label, int minW)
{
    if(component[curr] == label) return;
    component[curr] = label;
    for(Edge child: edges[curr])
    {
        if(child.w >= minW)
        {
            dfs(child.d, label, minW);
        }
    }
}

bool Valid(int minW)
{
    fill(component, component + n, -1);
    int numcorp = 0;
    cout << "Valid\n";
    for(int i = 0; i < n; i++)
    {
        if(component[i] < 0)
        {
            dfs(i, numcorp++, minW);
        }
    }
    cout << "Valid\n";
    for(int i = 0; i < n; i++)
    {
        if(component[i] != component[loc[i]])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    cin >> n >> m;
    loc = new int[n];
    component = new int[n];
    edges = new vector<Edge>[n];

    for(int i = 0; i < n; i++)
    {
        int index;
        cin >> index;
        loc[i] = --index;
    }

    for(int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        Edge e1, e2;
        e1.d = b - 1;
        e1.w = w;
        e2.d = a - 1;
        e2.w = w;

        edges[a].push_back(e1);
        edges[b].push_back(e2);
    }


    int minW = 0;
    int maxW = 1000000001;
    while(minW != maxW)
    {
        int mid = (minW + maxW + 1) / 2;
        if(Valid(mid))
        {
            minW = mid;
        }
        else
        {
            maxW = mid - 1;
        }
    }
    cout << "1";
    if(minW > 1e9)
    {
        minW = -1;
    }
    cout << minW;
    //delete(loc);
    //delete(component);
    //delete(edges);

    return 0;
}