#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int n, ans = 0;
    int sum = 0;
    cin >> n;
    int first[7];
    int last[7];
    fill(first, first + 7, 10000);
    fill(last, last + 7, 0);
    for (int i = 0; i < n; i++)
    {
        int a;
        int remain;
        cin >> a;
        sum += a;
        remain = sum % 7;
        first[remain] = min(first[remain], i);
        last[remain] = i;
    }

    for (int i = 0; i < 7; i++)
    {
        //cout << first[i] << " " << last[i];
        ans = max(ans, last[i] - first[i]);
    }
    cout << ans;
    return 0;
}