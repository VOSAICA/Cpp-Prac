#include <iostream>
using namespace std;

void print(int a[], int l)
{
    for (int i = 0; i < l; i++)
    {
        cout << a[i] << " ";
    }
}

void Merge(int a[], int b[], int i, int m, int n)
{
    int j, k;
    for (k = i, j = m + 1; i <= m, j <= n; k++)
    {
        if (a[j] < a[i])
        {
            b[k] = a[j++];
        }
        else
        {
            b[k] = a[i++];
        }
        while (i <= m)
        {
            b[k++] = a[i++];
        }
        while (j <= n)
        {
            b[k++] = a[j++];
        }
    }
}

void MergeSort(int a[], int b[], int length)
{
    int len = 1;
    while (len < length)
    {
        int s = len;
        len = 2 * s;
        int i = 0;
        while (i + len < length)
        {
            Merge(a, b, i, i +);
            i = i + len;
        }
    }
}

int main()
{
    int b[8] = {3, 1, 4, 2, 6, 7, 5, 0};
    print(b, 8);
    return 0;
}