#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<int> a, b, c;

int main()
{
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        a.push_back(i);
        c.push_back(i);
    }

    int temp, loop = 0;
    for (int i = 0; i < 4; i++)
    {
        cin >> temp;
        b.push_back(temp);
    }

    for (;;)
    {
        reverse(a.begin() + b[0] - 1, a.begin() + b[1]);
        reverse(a.begin() + b[2] - 1, a.begin() + b[3]);
        loop++;
        if (a == c)
            break;
    }
    k = k % loop;

    for (int i = 0; i < k; i++)
    {
        reverse(a.begin() + b[0] - 1, a.begin() + b[1]);
        reverse(a.begin() + b[2] - 1, a.begin() + b[3]);
    }

    for (int i = 0; i < n - 1; i++)
    {
        cout << a[i] << endl;
    }
    cout << a[n - 1];
    return 0;
}