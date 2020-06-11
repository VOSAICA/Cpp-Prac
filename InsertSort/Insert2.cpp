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

void InsertSort(int a[], int l)
{
    for(int i = 1; i < l; i++)
    {
        Print(a, 8);
        if(a[i] < a[i - 1])
        {
			int j = i;
			int current = a[i];
			while(current < a[j - 1] && j != 0){
				a[j] = a[j- 1];
				j--;
			}
			a[j] = current;
        }
    }
}

int main()
{
	int b[8] = {3, 1, 4, 5, 2, 0, 7, 6};
	InsertSort(b, 8);
	Print(b, 8);
    return 0;
}