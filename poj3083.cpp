#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
char maze[45][45];
bool flag[45][45];
int w, h;
int cnt;
bool p;
struct node
{
	int x, y, step;
};
void dfsl(int x, int y, int i)
{
	if (p || maze[x][y] == 'E')
	{
		p = true;
		return;
	}
	int cx = x + dx[i];
	int cy = y + dy[i];
	while (cx < 0 || cx >= h || cy < 0 || cy >= w || maze[cx][cy] == '#')
	{
		i = (i + 3) % 4;
		cx = x + dx[i];
		cy = y + dy[i];
	}
	cnt++;
	dfsl(cx, cy, (i + 1) % 4);
}
void dfsr(int x, int y, int i)
{
	if (p || maze[x][y] == 'E')
	{
		p = true;
		return;
	}
	int cx = x + dx[i];
	int cy = y + dy[i];
	while (cx < 0 || cx >= h || cy < 0 || cy >= w || maze[cx][cy] == '#')
	{
		i = (i + 1) % 4;
		cx = x + dx[i];
		cy = y + dy[i];
	}
	cnt++;
	dfsr(cx, cy, (i + 3) % 4);
}
int bfs(int start_x, int start_y)
{
	queue<node> q;
	node start;
	start.x = start_x;
	start.y = start_y;
	start.step = 1;
	q.push(start);
	flag[start_x][start_y] = 1;
	while (!q.empty())
	{
		node n = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int cx = n.x + dx[i];
			int cy = n.y + dy[i];
			if (flag[cx][cy] || cx < 0 || cx >= h || cy < 0 || cy >= w || maze[cx][cy] == '#')
				continue;
			start.x = cx;
			start.y = cy;
			start.step = n.step + 1;
			flag[cx][cy] = 1;
			if (maze[cx][cy] == 'E')
				return start.step;
			q.push(start);
		}
	}
}
int main()
{
	int t;
	int start_x, start_y;
	scanf("%d", &t);
	while (t--)
	{
		memset(flag, 0, sizeof(flag));
		scanf("%d%d", &w, &h);
		for (int i = 0; i < h; i++)
		{
			scanf("%s", &maze[i]);
			for (int j = 0; j < w; j++)
			{
				if (maze[i][j] == 'S')
				{
					start_x = i;
					start_y = j;
				}
			}
		}
		cnt = 1, p = false;
		dfsl(start_x, start_y, 0);
		printf("%d ", cnt);
		cnt = 1, p = false;
		dfsr(start_x, start_y, 0);
		printf("%d ", cnt);
		printf("%d\n", bfs(start_x, start_y));
	}
}