//2016 US Open Contest, Silver Problem 2. Diamond Collector
/*
 If we sort the diamonds by size and pick the sizes of the two smallest diamonds that will appear in each case, we can use binary search to figure out, in O(logN) time, the size of each case. However, there are too many diamonds for us to brute force try all possible pairs.

 There exists an optimal arrangement of diamonds such that all the diamonds in one case are strictly smaller than all the diamonds in the other case. This can be seen by taking an optimal arrangement which may not satisfy this constraint, taking the smallest diamond and putting all diamonds that can be presented with it on one case, and putting all the other diamonds in the other case.

 Imagine that we know beforehand what the maximum number of diamonds we can stick in a case given that all the diamonds have size at least K, as well as the maximum number of diamonds we can stick in a case given that all the diamonds have size at most K. We can then loop over all possible values of K.

 To actually compute the desired values, we can precompute for each diamond size how many diamonds we can have in a case with a given minimally/maximally-sized diamond. We can then loop over all of these precomputed values and save the maximum number of diamonds given that all diamonds are at least or at most a given size.
 
    Bessie想让这些陈列架上的钻石保持相似的大小，所以她不会把两个大小相差K以上的钻石同时放在一个陈列架上（如果两颗钻石的大小差值为K，那么它们可以同时放在一个陈列架上）。现在给出K，请你帮Bessie确定她最多一共可以放多少颗钻石在这两个陈列架上。
 */
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, k;
int *getRightmost(int *list, int k)
{
    int *ret = new int[n];
    int j = n - 1;
    for (int i = n - 1; i >= 0; i--)
    {
        while (j >= 0 && list[j] - list[i] > k)
        {
            j--;
        }
        ret[i] = j;
    }
    return ret;
}
int *getLeftmost(int *list, int k)
{
    int *ret = new int[n];
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        while (j < n && list[i] - list[j] > k)
        {
            j++;
        }
        ret[i] = j;
    }
    return ret;
}
int main()
{

    cin >> n >> k;
    int *list = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        cin >> list[i];
    }
    sort(list, list + n);
    // rightmostIndex[i] - the index of the smallest diamond that can be included given that the smallest diamond in the case has size list[i].
    // leftmostIndex[i] - the index of the smallest diamond that can be included given that the largest diamond in the case has size list[i].
    // leftSize - stores the maximum number of diamonds given that all diamonds have size at most list[i].
    int *leftmostIndex = getLeftmost(list, k);
    int *leftSize = new int[n];
    for (int i = 0; i < n; i++)
    {
        leftSize[i] = i - leftmostIndex[i] + 1;
        if (i > 0)
        {
            leftSize[i] = max(leftSize[i], leftSize[i - 1]);
        }
    }
    int *rightmostIndex = getRightmost(list, k);
    int *rightSize = new int[n];
    for (int i = n - 1; i >= 0; i--)
    {
        rightSize[i] = rightmostIndex[i] - i + 1;
        if (i < n - 1)
        {
            rightSize[i] = max(rightSize[i], rightSize[i + 1]);
        }
    }
    int ret = 0;
    for (int i = 0; i < n - 1; i++)
    {
        ret = max(ret, leftSize[i] + rightSize[i + 1]);
    }
    cout << ret;
    free(list);
    delete[] rightSize;
    delete[] leftSize;
}
