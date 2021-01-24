#include <fstream>
#include <iostream>
using namespace std;
int main()
{
    int n, a[100];
    ifstream fin;
    fin.open("sleepy.in");

    fin >> n;
    int times = n - 1;

    for (int i = 0; i < n; i++)
    {
        fin >> a[i];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] < a[i + 1])
            times -= 1;
        else
            break;
    }

    ofstream fout;
    fout.open("sleepy.out");
    fout << times;

    return 0;
}