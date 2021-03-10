#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    int n, times;
    char a[100];
    ifstream fin;
    fin.open("whereami.in");
    fin >> n;
    for (int i = 0; i < n; i++)
    {
        fin >> a[i];
    }

    ofstream fout;
    fout.open("whereami.out");
    for (int i = 1; i < n + 1; i++)
    {
        char b[100];
        for (int g = 1; (g < n - i + 1); g++) // start point
        {
            for (int f = 0; f < i; f++)
            {
                b[f] = a[f + g];
                cout << b[f];
            }
        }

        bool bigok = true;
        for (int j = 1; (j < n - i + 1); j++) // start point
        {
            int ok = 0;
            for (int x = j, y = 0; x <= j + i, y < i; x++, y++)
            {
                // cout << "x: " << x << " " << " y: " << y << "     ";
                if (a[x] == a[y])
                    ok += 1;
            }
            if (ok == i)
            {
                bigok = false;
                break;
            }
            cout << endl;
        }
        if (bigok == true)
        {
            cout << i;
            fout << i;
            break;
        }
    }

    return 0;
}
