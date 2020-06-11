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
    for(int i = 1; i < l + 1; i++)
    {
        Print(a, 8);
        if(a[i] < a[i - 1])//需要向前找
        {
            for(int j = i ; j > -1; j--)
            {
                if(a[j] < a[i])//找到了比它小的
                {
                    int temp = a[i];
                    for(int m = i; m > j + 1;m--)
                    {
                        a[m] = a[m - 1];
                    }
                    a[j + 1] = temp;
                    break;
                } 
                if(j == 0)//这个数本身是最小的,找到了最前
                {
                    int temp = a[j];
                    a[j] = a[i];
                    a[i] = temp;
                }
            }
        }
    }
}

int main()
{
	int b[8] = {4, 0, 7, 1, 2, 3, 6, 5};  
    InsertSort(b, 8);
    return 0;
}
