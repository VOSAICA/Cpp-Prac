#include <iostream>
#include <fstream>
#include <set>
using namespace std;

int N;
long b[1000], a[1000];
set<long> check;

int main()
{
    ifstream fin;
    fin.open("photo.in");
    fin >> N;
    for (int i = 0; i < N - 1; i++)
    {
        fin >> b[i];
    }
    for (int i = 1; i < N; i++)
    {
        bool zero = false;
        a[0] = i;
        check.insert(a[0]);
        for (int j = 1; j < N; j++)
        {
            a[j] = b[j - 1] - a[j - 1];
            if (a[j] <= 0)
                zero = true;
            check.insert(a[j]);
        }
        if (check.size() == N && zero == false)
            break;
        else
            check.clear();
    }
    ofstream fout;
    fout.open("photo.out");
    for (int i = 0; i < N - 1; i++)
    {
        fout << a[i] << " ";
    }
    fout << a[N - 1];
    return 0;
}
