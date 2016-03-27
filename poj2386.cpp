#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 105;
int n, m;

char field[MAXN][MAXN];

void dfs(int i, int j)
{
	field[i][j] = '.';
	for (int dx = -1; dx <= 1; dx++)
	{
		for (int dy = -1; dy <= 1; dy++)
		{
			if (i + dx >= 0 && i + dx < n && 
				j + dy >=0 && j + dy < m &&
				field[i + dx][j + dy] == 'W')
				dfs(i + dx, j + dy);
		}
	}
}

void solve()
{
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (field[i][j] == 'W')
			{
				dfs(i, j);
				ans++;
			}
		}
	}
	printf("%d\n", ans);
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", &field[i]);
	solve();
}