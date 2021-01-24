#include <fstream>
#include <iostream>
using namespace std;

struct node
{
    int a = 0;
    int b = 0;
    int c = 0;
    int color = 1;
} nodes[1000];

int main()
{
    ifstream in("revegetate.in");
    int N, M, a[150], b[150]; //N块草地，M头奶牛
    in >> N >> M;
    for (int i = 0; i < M; i++)
    {
        in >> a[i] >> b[i];
    }

    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (i == a[j])
            {
                if (nodes[i].a == 0)
                    nodes[i].a = b[j];
                else if (nodes[i].b == 0)
                    nodes[i].b = b[j];
                else
                    nodes[i].c = b[j];
            }
            else if (i == b[j])
            {
                if (nodes[i].a == 0)
                    nodes[i].a = a[j];
                else if (nodes[i].b == 0)
                    nodes[i].b = a[j];
                else
                    nodes[i].c = a[j];
            }
        }
    }
    ofstream out("revegetate.out");
    for (int i = 1; i < N + 1; i++)
    {
        for (int g = 1; g < 5; g++)
        {
            if (nodes[i].c != 0)
            {
                if ((nodes[i].color == nodes[nodes[i].a].color) || (nodes[i].color == nodes[nodes[i].b].color) || (nodes[i].color == nodes[nodes[i].c].color))
                    nodes[i].color = g;
            }
            else if (nodes[i].c == 0)
            {
                if ((nodes[i].color == nodes[nodes[i].a].color) || (nodes[i].color == nodes[nodes[i].b].color))
                    nodes[i].color = g;
            }
            else if (nodes[i].b == 0)
            {
                if (nodes[i].color == nodes[nodes[i].a].color)
                {
                    nodes[i].color = g;
                }
            }
            else
                break;
        }
        out << nodes[i].color;
    }

    return 0;
}
