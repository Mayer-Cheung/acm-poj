#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int MAXN = 305;
int vis[MAXN][MAXN], dist[MAXN][MAXN];

int dir[8][2] = {1, 2, 1, -2, -1, 2, -1, -2, 2, 1, 2, -1, -2, 1, -2, -1};
int kase = 0, X, Y;
int sx, sy, ex, ey;

struct Node
{
    int x, y;
    Node(int r, int c)
    {
        x = r, y = c;
    }
};

queue<Node> Q;

int BFS()
{
    while (!Q.empty())
        Q.pop();
    if (sx == ex && sy == ey)
        return 0;
    dist[sx][sy] = 0;
    vis[sx][sy] = kase;
    Q.push(Node(sx, sy));
    while (!Q.empty())
    {
        Node node = Q.front();
        Q.pop();
        int r = node.x, c = node.y;
        for (int i = 0; i < 8; i++)
        {
            int nx = r + dir[i][0];
            int ny = c + dir[i][1];
            if (nx >= 0 && nx < X && ny >= 0 && ny < Y && vis[nx][ny] != kase)
            {
                if (nx == ex && ny == ey)
                    return dist[r][c] + 1;
                dist[nx][ny] = dist[r][c] + 1;
                vis[nx][ny] = kase;
                Q.push(Node(nx, ny));
            }
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        kase++;
        scanf("%d", &X);
        Y = X;
        scanf("%d%d", &sx, &sy);
        scanf("%d%d", &ex, &ey);
        printf("%d\n", BFS());
    }
}