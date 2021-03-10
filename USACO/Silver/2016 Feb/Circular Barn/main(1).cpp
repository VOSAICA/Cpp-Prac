// USACO 2016 February Contest, Silver Problem 1. Circular Barn
// n头牛 n个房间
//在i房间排队的有ci头牛
//***** STL rotate函数
/*
 The first solution to this problem that people will likely come up with is something like the following: process each of the
 cows in some order. For each cow, have it walk around the barn until it comes across the first empty door, then enter that
 door.

 The important insight is to notice that for any two cows A and B, if A walks past B's start point, then A can exit at a door
 before B's endpoint. This is because, if A walked past both B's start and end points, then we could obtain a solution that's
 just as good by switching A and B's endpoints. Thus, if we are choosing between many cows to drop off at one door, we may as
 well choose the cow that started walking first without hurting our solution.



 This suggests an order in which to process the cows: we simply start at any point on the circle and begin walking all the cows
 at that point around the circle. We keep track of the distance walked by all our active cows, and pick up any cows we encounter
 along the way. At every door, we "drop a cow off", and subtract 1 from our running total. We have to make sure that we find a
 point to start at such that we always have a cow to drop off at each door, and such a point is guaranteed to exist in some
 optimal solution because of our insight above. One way to find this point is to go around the circle like this once and finding
 the point where we have the largest number of cows. Then we can start at that point when we actually want to compute the
 solution.

 * We have to make sure that we find a point to start at such that we always have a cow to drop off at each door.




     STL rotate函数 - rotate(beg,newBeg,end)

     将区间[beg,end)内的元素进行旋转，执行后*newBeg成为新的第一元素；
     找到有牛排队最多的门


    1²+2²+3²+...+n²=n(n+1)(2n+1)/6

    证明:

    (n+1)³=n³+3n²+3n+1

    (n+1)³-n³=3n²+3n+1

    n³-(n-1)³=3(n-1)²+3(n-1)+1

    ...

    3³-2³=3*2²+3*2+1

    2³-1³=3*1²+3*1+1

    两边分别相加得

    (n+1)³-1³=3*(1²+2²+...+n²)+3(1+2+...+n)+1*n

    (n³+3n²+3n)-3n(n+1)/2-n=3Sn

    3Sn=n(2n²+3n+1)/2=n(n+1)(2n+1)/2

    Sn=n(n+1)(2n+1)/6
 */

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
// n^2的求和公式
long long sumn2(long long v)
{
    return v * (v + 1) * (2 * v + 1) / 6;
}

int main()
{
    int N;
    cin >> N;
    vector<long long> A(N);
    //求出有多少头牛还需要安排房间
    int c = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        c = max(0ll, c + A[i] - 1);
    }

    for (int i = 0;; i++)
    {
        if (c == 0)
        {
            rotate(A.begin(), A.begin() + i, A.begin() + N);
            break;
        }
        c = max(0ll, c + A[i] - 1);
    }

    long long result = 0;
    for (int i = 0; i < N; i++)
    {
        result += sumn2(A[i] + c - 1) - sumn2(c - 1);
        c = max(0ll, c + A[i] - 1);
    }
    cout << result << endl;
}
