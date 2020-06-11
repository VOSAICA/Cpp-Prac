#include <iostream>
using namespace std;

void print(int a[], int l)
{
    for(int i = 0;i < l;i++)
    {
        cout<<a[i]<<" ";
    }
}

void swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(int a[], int low, int high)
{
    int pivot = a[low];
    while(low < high)
    {
        while(low < high && a[high] > pivot) --high;
        while(low < high && a[low] < pivot) ++low;
        swap(a[low], a[high]);

    }
    return low;
}

void quickSort(int a[], int low, int high)
{
    if(low < high)
    {
        int pivotLocation = partition(a, low, high);
        quickSort(a, low, pivotLocation - 1);
        quickSort(a, pivotLocation + 1, high);
    }
}

int main()
{
    int b[8] = {3, 1, 4, 2, 6, 7, 5, 0};
    quickSort(b, 0, 7);
    print(b, 8);
    return 0;
}