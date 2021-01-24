#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, m, k;
vector<int> a, b, c, temp, sequence;

vector<int> Mset(vector<int> a, vector<int> sequence)
{
    for (int i = 0; i < n; i++)
    {
        temp[i] = a[sequence[i] - 1];
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = temp[i];
    }
    return a;
}

int main()
{
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        a.push_back(i);
        c.push_back(i);
        temp.push_back(i);
        sequence.push_back(i);
    }

    int repli, loop = 0;
    for (int i = 0; i < m * 2; i++)
    {
        cin >> repli;
        b.push_back(repli);
    }
    for (int f = 0; f < m * 2; f += 2) // for one set
        reverse(sequence.begin() + b[f] - 1, sequence.begin() + b[f + 1]);

    // a = Mset(a, sequence);
    //
    // cout << "a ";
    // for (int i = 0; i < n; i++){
    //     cout << a[i];
    // }cout << endl;
    // for (int i = 0; i < n; i++){
    //     cout << temp[i];
    // }

    for (;;)
    {
        a = Mset(a, sequence);
        loop++;
        if (a == c)
            break;
    }
    k = k % loop;

    for (int i = 0; i < k; i++)
    {
        a = Mset(a, sequence);
    }

    for (int i = 0; i < n - 1; i++)
    {
        cout << a[i] << endl;
    }
    cout << a[n - 1];
    return 0;
}