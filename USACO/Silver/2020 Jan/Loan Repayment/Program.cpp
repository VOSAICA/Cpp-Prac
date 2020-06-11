#include<iostream>
#include<algorithm>
#include<fstream>
using namespace std;


long long N, K, M;

int valid(long long N, long long K, long long M, long long X)
{
    long long G = 0;

    while (K > 0 && G < N)
    {
        long long Y = (N - G) / X;
        if (Y < M)
        {
            long long leftover = (N - G + M - 1) / M;
            return leftover <= K;
        }
        long long maxmatch = N - X * Y;
        long long numdays = (maxmatch - G) / Y + 1;
        if (numdays > K)
        {
            numdays = K;
        }
        G += Y * numdays;
        K -= numdays;
    }
    return G >= N;
}
int main()
{
    ifstream fin;
    //fin.open("loan.in");
    cin >> N >> K >> M;
    //ofstream fout;

    //freopen("loan.out","w",stdout);  //输出重定向，输出数据将保存在mountains.out文件中

    long long low, high, mid;
    low = 1;
    high = 1e12;
    while (low < high)
    {
        mid = (high + low) / 2;
        if (valid(N, K, M, mid))
        {
            low = mid;
        }
        else
        {
            high = mid - 1;
        }
    }
    //printf("lld\n", N);
    cout << high;
    //fclose(stdout);
    return 0;
}
