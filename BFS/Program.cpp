#include<iostream>
#include<queue>
using namespace std;

struct point{
    int x, y;
    int time;
    int step;
};

queue <point> Q;
char map[100][100];
int mintime[100][100];
int ax, ay;
int l, h;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

int bfs(point s)
{
    Q.push(s);
    point hd;
    while(Q.empty() == false)
    {
        hd = Q.front();
        Q.pop();
        for(int i = 0; i < 4; i++)
        {
            int x = hd.x + dir[i][0];
            int y = hd.y + dir[i][1];

            if(x >= 0 && y >= 0 && x < l && y < h && map[x][y] != '#')
            {
                point t;
                t.x = x;t.y = y;
                t.step = hd.step + 1;
                t.time = hd.time + 1;
                if(map[x][y] == 'x') t.time += 1;
                if(mintime[x][y] > t.time)
                {
                    mintime[x][y] = t.time;
                    Q.push(t);
                }
            }
        }
    }
    return mintime[ax][ay];
}



int main()
{
    cin >> h >> l;
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < l; j++)
        {
            cin >> map[i][j];
        }
    }

    int sx, sy;
    point start;

    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < l; j++)
        {
            mintime[i][j] = 10000;
            if(map[i][j] == 'a')
            {
                ax = i; ay = j;
            }
            else if(map[i][j] == 'r')
            {
                sx = i; sy = j;
            }
        }
    }

    start.x = sx;start.y = sy;start.step = 0;start.time = 0;
    mintime[sx][sy] = 0;
    int time = bfs(start);

    if(time == 10000)
    {
        cout << "can not" << endl;
    }
    else
    {
        cout << time << endl;        
    }
    
    return 0;
}
