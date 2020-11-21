#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
    float w;
    float v;
    float r;
} nodes[1000];

int c, n;

bool compare(node a, node b)
{
    return a.r > b.r;
}

int main()
{
    cin >> c;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> nodes[i].v;
        cin >> nodes[i].w;
        nodes[i].r = nodes[i].v / nodes[i].w;
    }

    sort(nodes, nodes + n, compare);

    float value = 0;

    for (int i = 0; i < n; i++)
    {
        if (c > nodes[i].w)
        {
            value += nodes[i].v;
            c -= nodes[i].w;
        }
        else
        {
            float proportion = c / nodes[i].w;
            value += nodes[i].v * proportion;
        }
    }

    cout << value;

    return 0;
}
