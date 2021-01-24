#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int n, k;
string essay[100];

int main()
{
    ifstream fin;
    fin.open("word.in");
    fin >> n >> k;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        fin >> essay[i];
    }

    ofstream fout;
    fout.open("word.out");
    for (int i = 0; i < n - 1; i++)
    {
        fout << essay[i];
        sum += essay[i].length();
        if (essay[i + 1].length() <= k - sum)
            fout << " ";
        if (essay[i + 1].length() > k - sum)
        {
            fout << "\n";
            sum = 0;
        }
        if (sum == k)
        {
            fout << "\n";
            sum = 0;
        }
    }
    fout << essay[n - 1];
    return 0;
}
