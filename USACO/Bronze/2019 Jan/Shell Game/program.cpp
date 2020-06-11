#include<iostream>
#include<fstream>
#include <stdint.h>
#include <Windows.h>
using namespace std;

int main()
{
    int n, score = 0;
    ifstream in;
    in.open("shell.in");
    in >> n;
    int a[100], b[100], g[100];
    for(int i = 0; i < n; i++)
    {
        in >> a[i] >> b[i] >> g[i];
    }

    for(int i = 1; i < 4; i++)
    {   
        int temp = 0, place = i;
        for(int j = 0; j < n; j++)
        {
            if (place == a[j]) place = b[j];
            else if(place == b[j]) place = a[j];
            if(g[j] == place) temp++;
        }
        score = max(score, temp);
    }

    ofstream out;
    out.open("shell.out");
    out << score;

    return 0;
}
