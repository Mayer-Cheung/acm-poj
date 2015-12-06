#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 105;

int maze[MAXN][MAXN];
int dir[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};
int ans, cnt, C, R, K;

void dfs(int x, int y)
{
	if (x < 1 || x > R || y < 1 || y > C || maze[x][y] == 0)
		return;
	maze[x][y] = 0;
	cnt++;
	for (int i = 0; i < 4; i++)
		dfs(x + dir[i][0], y + dir[i][1]);
}

int main()
{
	while (scanf("%d%d%d", &R, &C, &K) != EOF)
	{
		for (int i = 1; i <= R; i++)
			for (int j = 1; j <= C; j++)
				maze[i][j] = 0;
		while (K--)
		{
			int i, j;
			scanf("%d%d", &i, &j);
			maze[i][j] = 1;
		}
		ans = 0;
		for (int i = 1; i <= R; i++)
			for (int j = 1; j <= C; j++)
				if (maze[i][j])
				{
					cnt = 0;
					dfs(i, j);
					ans = max(cnt, ans);
				}

		printf("%d\n", ans);
	}
}