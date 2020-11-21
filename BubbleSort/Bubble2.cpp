#include <iostream>
using namespace std;

void Print(int a[], int l)
{
	for (int i = 0; i < l; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

void BubbleSort(int a[], int l)
{
	int newl = l - 1;
	for (int j = 0; j < l; j++)
	{
		bool change = false;
		for (int i = 0; i < newl; i++)
		{
			if (a[i] >= a[i + 1])
			{
				int temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
				change = true;
			}
		}
		newl--;
		if (change == false)
		{
			break;
		}
		Print(a, 8);
	}
}

int main()
{
	int b[8] = {2, 1, 6, 4, 5, 3, 8, 7};
	BubbleSort(b, 8);
	Print(b, 8);
}
