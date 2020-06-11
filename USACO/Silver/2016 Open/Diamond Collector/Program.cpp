#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n, k;

int* getRightMost(int* list, int k)
{
    int* ret = new int[n];
    int j = n - 1;
    for(int i = n - 1; i >= 0; i--)
    {
        while (j >= 0 && list[j] - list[i] > k)
        {
            j--;
        }
        ret[i] = j;
    }
    return ret;
}
int* getLeftMost(int* list, int k)
{
    int* ret = new int[n];
    int j = 0;
    for(int i = 0; i < n; i++)
    {
        while (j <= n - 1 && list[i] - list[j] > k)
        {
            j++;
        }
        ret[i] = j;
    }
    return ret;
}

int main()
{
    freopen("diamond.in","r",stdin);
    freopen("diamond.out","w",stdout);

    cin >> n >> k;
    int* list = (int*)malloc(n*sizeof(int));
    for(int i = 0; i < n; i++)
    {
        cin >> list[i];
    }
    sort(list, list + n);
    int* leftMostIndex = getLeftMost(list, k);
    int* leftSize = new int[n];
    for(int i = 0; i < n; i++)
    {
        leftSize[i] = i - leftMostIndex[i] + 1;
        if (i > 0)
        {
            leftSize[i] = max(leftSize[i], leftSize[i - 1]);
        }
        
    }
    int* rightMostIndex = getRightMost(list, k);
    int* rightSize = new int[n];
    for(int i = n - 1; i >= 0; i--)
    {
        rightSize[i] = rightMostIndex[i] - i + 1;
        if (i < n - 1)
        {
            rightSize[i] = max(rightSize[i], rightSize[i + 1]);
        } 
    }
    int ret = 0;
    for(int i = 0; i < n - 1; i++)
    {
        ret = max(ret, rightSize[i] + leftSize[i + 1]);
    }
    cout << ret;
    free(list);

    fclose(stdin);
    fclose(stdout);
    delete[] rightSize;
    delete[] leftSize;

    return 0;
}