#include<bits/stdc++.h>
using namespace std;

struct shopmilk
{
    int quat;
    int price;
}shops[100001];

bool cmp(shopmilk a, shopmilk b)
{
    return a.price > b.price;
}
bool bts(int a, int b)
{
    return a > b;
}

int N, M, R;
long long cow[100001], farmer[100001];

int main()
{
    ifstream fin("rental.in");
    ofstream fout("rental.out");
    fin >> N >> M >> R;

    for (int i = 0; i < N; i++)
    {
        fin >> cow[i];
    }

    int temp1, temp2;
    for (int i = 0; i < M; i++)
    {
        fin >> shops[i].quat;
        fin >> shops[i].price;
    }

    for (int i = 0; i < R; i++)
    {
        fin >> farmer[i];
    }
    
    sort(cow, cow + N, bts);
    sort(shops, shops + M, cmp);
    sort(farmer, farmer + R, bts);

    for (int i = 0; i < N; i++)
    {
        cout << shops[i].price;
    }

    int left = shops[0].quat;
    for (int i = 0; i < M; i++)
    {
        
    }
    

    fout.close();
    return 0;
}