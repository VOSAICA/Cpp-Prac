#include<iostream>
#include<fstream>
using namespace std;
long K, N;
long a[1000];

long sigma(long a, long b)
{
    long ans = 0;
    if(((b - a) %2) == 1)
    {
        ans = (b + a) * (b - a + 1) / 2;
    }
    else
    {
        ans = a + sigma(a + 1, b);
    }
    return ans;
}

long time_request(long x)
{
    long speed = 0;
    long terminalSpeed = x;
    long time = 0;
    long travel;
    long leftDis = 0;

    time = terminalSpeed - speed;//b
    travel = sigma(speed, terminalSpeed);

    if(travel == K)
    {
        return time;
    }
    time++;//给最终速度的一秒,下面开始求中间那段

    if(travel > K)
    {
        time = time_request(terminalSpeed - 1);
        return time;
    }


    leftDis = K - travel - terminalSpeed;
    long Sum = 0;
    long Start = terminalSpeed;
    long End = terminalSpeed;
    for(long i = 1; i > 0; i++)//加速减速过程
    {
        if(leftDis - Sum >= Start + 1)
        {
            Start++; time++; Sum = Sum + Start;
        }
        else break;
        if(leftDis - Sum >= End + 1)
        {
            End++; time++; Sum = Sum + End;
        }
        else break;
    }
    if(Sum + travel + terminalSpeed != K) time++;//不够再加速，在之前的任意一段距离保持速度，时间+1

    return time;
}

int main()
{
    ifstream fin;
    fin.open("race.in");
    fin >> K >> N;
    ofstream fout;
    fout.open("race.out");
    for(long i = 0; i < N; i++)
    {
        fin >> a[i];
        if(i == N - 1)//最后一行不换行
        {
            fout << time_request(a[i]);
            break;
        }
        else fout << time_request(a[i]) << endl;
    }
    return 0;
}