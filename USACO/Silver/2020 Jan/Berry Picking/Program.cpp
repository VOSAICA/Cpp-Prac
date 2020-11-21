#include <iostream>
#include <algorithm>
using namespace std;
int N, K, M = 0;
int mod;
int A[100];
bool cmp(int a, int b)
{
    return (a % mod) > (b % mod);
}

int main()
{
    cin >> N >> K;
    int M = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        M = max(M, A[i]);
    }

    int best = 0;
    for (int b = 1; b <= M; b++)
    {
        int full = 0;
        for (int j = 0; j < N; j++)
        {
            full += A[j] / b;
        }
        if (full < K / 2)
        {
            break;
        }
        if (full >= K)
        {
            best = max(best, b * (K / 2));
            continue;
        }
        mod = b;
        sort(A, A + N, cmp);
        int cur = b * (full - K / 2);
        for (int i = 0; i < N && i + full < K; i++)
        {
            cur += A[i] % b;
        }
        best = max(best, cur);
    }
    cout << best << endl;
    return 0;
}