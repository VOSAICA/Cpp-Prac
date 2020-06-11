#include<iostream>
#include<fstream>
using namespace std;
long K, N;
long a[1000];

long sigma(int a, int b)
{
    int ans = 0;
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

long time_request(int x)
{
    long speed = 0;
    long terminalSpeed = x;
    long time = 0;
    long travel;
    long leftDis = 0;

    time = terminalSpeed - speed;//b
    travel = sigma(speed, terminalSpeed);

    cout <<"time1: "<< time << endl;
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
    cout <<"time0: "<< time << endl;


    leftDis = K - travel - terminalSpeed;
    long Sum = 0;
    long Start = terminalSpeed;
    long End = terminalSpeed;
    for(long i = 1; i > 0; i++)//加速减速过程
    {
        if(leftDis - Sum >= Start + 1)
        {
            Start++; time++; Sum = Sum + Start;
            cout << "Start: " << Start << endl;
            cout << "Sum: " << Sum << endl;
        }
        else break;
        if(leftDis - Sum >= End + 1)
        {
            End++; time++; Sum = Sum + End;
            cout << "End: " << End << endl;
            cout << "Sum: " << Sum << endl;
        }
        else break;
    }
    cout << travel << endl;
    if(Sum + travel + terminalSpeed != K) time++;//不够再加速，在之前的任意一段距离保持速度，时间+1

    return time;


}

int main()
{
    K = 55;
    N = 1;
    int a = time_request(10);
    cout << a;
    return 0;
}