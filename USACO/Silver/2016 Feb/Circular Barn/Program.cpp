#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

long long sumn2(long long v)
{
    return v * (v + 1) * (2 * v + 1) / 6;
}

int N;
int main()
{
    cin >> N;
    vector<long long> A(N);
    int c = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        c = max(0ll, c + A[i] - 1);
    }

    int i = 0;
    while (true)
    {
        if (c == 0)
        {
            rotate(A.begin(), A.begin() + i, A.begin() + N);
            break;
        }
        c = max(0ll, c + A[i] - 1);
        i++;
    }

    long long result = 0;
    for (int i = 0; i < N; i++)
    {
        result += sumn2(c + A[i] - 1) - sumn2(c - 1);
        c = max(0ll, c + A[i] - 1);
    }
    cout << result;

    return 0;
}