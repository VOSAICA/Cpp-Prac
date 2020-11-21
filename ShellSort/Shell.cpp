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

void ShellSort(int a[], int l)
{

	int pace = l / 2;
	while (pace >= 1)
	{
		cout << "pace: " << pace << endl;
		for (int i = pace; i < l; i++)
		{
			if (a[i] < a[i - pace])
			{
				int j = i;
				int current = a[i];
				while (current < a[j - pace] && (j - pace) > -1)
				{
					a[j] = a[j - pace];
					j -= pace;
				}
				a[j] = current;
			}
			Print(a, 8);
		}
		pace = pace / 2;
	}
}

int main()
{
	int b[8] = {3, 1, 7, 6, 2, 0, 4, 5};
	ShellSort(b, 8);
	Print(b, 8);
	return 0;
}