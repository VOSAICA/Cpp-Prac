#include <iostream>
using namespace std;

char a[1000], b[1000];
int n, ans = 0, record = -2;

int main()
{
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            if (i != record + 1)
                ans++;
            record = i;
        }
    }
    cout << ans;
    return 0;
}