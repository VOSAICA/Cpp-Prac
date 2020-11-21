#include <iostream>
#include <fstream>
#include <stdint.h>
#include <Windows.h>
using namespace std;

int main()
{
    ifstream in;
    in.open("traffic.in");
    int n;
    in >> n;

    int x = -99999;
    int y = 99999;

    int a[100];
    int b[100];
    string c[100];

    for (int i = 0; i < n; i++)
    {
        in >> c[i] >> a[i] >> b[i];
        cout << "a: " << a[i];
        cout << "b: " << b[i];
    }

    ofstream out;
    out.open("traffic.out");
    for (int i = n - 1; i > -1; i--)
    {
        if (c[i] == "none")
        {
            x = max(x, a[i]);
            y = min(y, b[i]);
        }
        if (c[i] == "on")
        {
            x -= (max(a[i], b[i]));
            y -= (min(a[i], b[i]));
        }
        if (c[i] == "off")
        {
            x += min(a[i], b[i]);
            y += max(a[i], b[i]);
        }
    }
    out << x << " " << y;

    for (int i = 0; i < n; i++)
    {
        if (c[i] == "none")
        {
            x = max(x, a[i]);
            y = min(y, b[i]);
        }
        if (c[i] == "off")
        {
            x -= max(a[i], b[i]);
            y -= min(a[i], b[i]);
        }
        if (c[i] == "on")
        {
            x += min(a[i], b[i]);
            y += max(a[i], b[i]);
        }
    }
    out << x << " " << y << endl;
    return 0;
}