#include<iostream>
#include<algorithm>
using namespace std;

int n;
struct point{
    int x;
    int y;
}points [1000];

int findFarX(point a){
    int horizonLen = 0;
    for (int i = 0; i < n; i++){
        if (points[i].x != a.x && points[i].y == a.y){
            horizonLen = max(horizonLen, abs(points[i].x - a.x));
        }
    }
    return horizonLen;
}

int findFarY(point a){
    int horizonLen;
    int verticalLen = 0, area = 0;
    for (int i = 0; i < n; i++){
        if (points[i].y != a.y && points[i].x == a.x){
            horizonLen = findFarX(points[i]);
            if (horizonLen == 0) return 0;
            else area = max(area, abs(points[i].y - a.y) * horizonLen);
        }
    }
    return area;
}

int main()
{
    freopen("triangles.in","r",stdin);
    freopen("triangles.out","w",stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> points[i].x >> points[i].y;
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, findFarY(points[i]));
    cout << ans;
    return 0;
}