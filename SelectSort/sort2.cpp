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

void SelectSort(int a[], int l)
{
	for(int i = 0; i < (l / 2); i++)
    {
        int min = a[i];
        int max = a[i];
        int indexMin = 0;
        int indexMax = 0;
        cout<<"i: "<<i<<endl;        
        for(int j = i; j < l; j++)
        {
            if(a[j] < min)
            {
                min = a[j];
                indexMin = j;
            }
            if(a[j] > max)
            {
                max = a[j];
                indexMax = j;
            }
        }
        //cout<<"l - i: "<<l - 1 - i<<endl;
        cout<<min<<endl<<max<<endl;
        int temp = a[i];
        a[i] = a[indexMin];
        a[indexMin] = temp;

        int temp2 = a[l - 1 - i];
        a[l - 1 - i] = a[indexMax];
        a[indexMax] = temp2;
    }
}

int main()
{
	int b[8] = {7, 4, 3, 5, 2, 6, 1, 0};
	SelectSort(b, 8);
	Print(b, 8);
    return 0;
}