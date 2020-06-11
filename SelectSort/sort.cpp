#include<iostream>
using namespace std;

void Print(int a[], int l)
{
	for (int i = 0; i < l; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

int Find(int a[], int s, int l)
{
    int min = a[s];
    int index;
    for(int i = s; i < l; i++)
    {
        if (a[i] < min){
            min = a[i];
            index = i;
        }
    }
    return index;
}

void SelectSort(int a[], int l)
{
	for(int i = 0; i < l; i++){
        int change = Find(a, i, l);
        int temp = a[i];
        a[i] = a[change];
        a[change] = temp;
    }
}

int main()
{
	int b[8] = {7, 4, 3, 5, 2, 6, 1, 0};
	SelectSort(b, 8);
	Print(b, 8);
    return 0;
}