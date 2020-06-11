#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    int N, count = 0;
    int a[100000];
    ifstream fin;
    fin.open("sort.in");
    fin >> N;

    for(int i = 0; i < N; i++)
    {
        fin >> a[i];
    }

    bool sorted = false;
    while(sorted == false)
    {
        sorted = true;
        count++;
        for(int i = 0; i <= N - 2; i++)
        {
            if(a[i + 1] < a[i])
            {
                swap(a[i], a[i + 1]);
                sorted = false;
            }
        }
    }

    ofstream fout;
    fout.open("sort.out");
    fout << count;
    return 0;
}
