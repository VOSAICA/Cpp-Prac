#include <bits/stdc++.h>
using namespace std;

int N, Q, hay[100000];

int ans(int a, int b)
{
    int front = lower_bound(hay, hay + N, a) - hay;
    int back = upper_bound(hay, hay + N, b) - hay;
    return back - front;
}

int main()
{
    ifstream fin("haybales.in");
    ofstream fout("haybales.out");

    fin >> N >> Q;

    for (int i = 0; i < N; i++)
    {
        fin >> hay[i];
    }
    sort(hay, hay + N);

    int a, b;
    for (int i = 0; i < Q; i++)
    {
        fin >> a >> b;
        if (i != Q - 1)
            fout << ans(a, b) << endl;
        else
            fout << ans(a, b);
    }

    fout.close();
    return 0;
}
