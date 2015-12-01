#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 305;
const int INF = 1 << 29;

int n, m, a[MAXN], f[MAXN][MAXN];

int main()
{
	while (scanf("%d%d", &n, &m) != EOF)
	{
		for (int i = 1; i <= n; i++)
		{
			f[i][i] = 0;
			for (int j = i + 1; j <= n; j++)
				f[i][j] = f[j][i] = INF;
		}

		for (int i = 0; i < m; i++)
		{
			int cnt;
			scanf("%d", &cnt);
			for (int j = 0; j < cnt; j++)
			{
				scanf("%d", &a[j]);
				for (int k = 0; k < j; k++)
					f[a[j]][a[k]] = f[a[k]][a[j]] = 1;
			}
		}

		for (int k = 1; k <= n; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					f[i][j] = min(f[i][j], f[i][k] + f[k][j]);

		int ans = INF;
		for (int i = 1; i <= n; i++)
		{
			int dist = 0;
			for (int j = 1; j <= n; j++)
				if (i != j)
					dist += f[i][j];
				ans = min(ans, dist);
		}

		printf("%d\n", ans * 100 / (n - 1));
	}
}