#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 25;

int n, m, ans;
char map[MAXN][MAXN];
bool visit[MAXN][MAXN];

void search(int row, int col)
{
	if (row < 0 || row >= n || col < 0 || col >= m || map[row][col] == '#' || visit[row][col])
		return;
	visit[row][col] = true;
	ans++;
	search(row, col + 1);
	search(row, col - 1);
	search(row + 1, col);
	search(row - 1, col);
}

int main()
{
	while (scanf("%d%d", &m, &n) && n + m)
	{
		memset(visit, 0, sizeof(visit));
		int row, col;
		ans = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%s", map[i]);
			for (int j = 0; j < m; j++)
			{
				if (map[i][j] == '@')
				{
					row = i;
					col = j;
				}
			}
		}
		search(row, col);
		printf("%d\n", ans);
	}
}