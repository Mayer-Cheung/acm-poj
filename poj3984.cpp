#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;

struct Node
{
	int x, y;
}pre[5][5];

int dir[4][2] = {-1, 0, 0, -1, 1, 0, 0, 1};
int map[5][5];
bool used[5][5];
queue<Node> que;

void bfs()
{
	used[0][0] = true;
	que.push((Node){0, 0});
	while (!que.empty())
	{
		Node tmp = que.front();
		que.pop();
		if (tmp.x == 4 && tmp.y == 4)
			break;
		for (int i = 0; i < 4; i++)
		{
			int tx = tmp.x + dir[i][0];
			int ty = tmp.y + dir[i][1];
			if (!used[tx][ty] && tx >= 0 && tx < 5 && ty >= 0 && ty < 5 && map[tx][ty] == 0)
			{
				que.push((Node){tx, ty});
				used[tx][ty] = true;
				pre[tx][ty] = (Node){tmp.x, tmp.y};
			}
		}
	}
	stack<Node> stk;
	stk.push((Node){4, 4});
	while (true)
	{
		Node tmp = (Node){pre[stk.top().x][stk.top().y].x, pre[stk.top().x][stk.top().y].y};
		stk.push(tmp);
		if (tmp.x == 0 && tmp.y == 0)
			break;
	}
	while (!stk.empty())
	{
		printf("(%d, %d)\n", stk.top().x, stk.top().y);
		stk.pop();
	}
}

int main()
{
	memset(map, 0, sizeof(map));
	memset(used, 0, sizeof(used));
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			scanf("%d", &map[i][j]);
	bfs();
}