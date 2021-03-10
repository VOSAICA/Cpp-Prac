#include <fstream>
#include <iostream>
using namespace std;

struct cow
{
    string name;
    int alpha;
    string before = "";
    string after = "";
} cows[8];

int main()
{
    string cowname[8] = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};
    for (int i = 0; i < 8; i++)
    {
        cows[i].name = cowname[i];
        cows[i].alpha = i;
    }

    int n;
    string waste;
    ifstream fin;
    fin.open("lineup.in");
    fin >> n;

    for (int i = 0; i < n; i++)
    {
        string tempA, tempB;
        fin >> tempA;
        for (int j = 0; j < 4; j++)
        {
            fin >> waste;
        }
        fin >> tempB;
    }

    return 0;
}
