#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 105;
const int INF = 1e9;
int a, b, n, d[MAXN][MAXN];

int main()
{
	while (scanf("%d%d%d", &n, &a, &b) == 3)
	{
		//  initialization
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				d[i][j] = i == j? 0 : INF;

		for (int i = 1; i <= n; i++)
		{
			int k, u;
			scanf("%d", &k);
			for (int j = 1; j <= k; j++)
			{
				scanf("%d", &u);
				if (j == 1)
					d[i][u] = 0;
				else
					d[i][u] = 1;
			}
		}

		for (int k = 1; k <= n; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

		printf("%d\n", d[a][b] == INF? -1 : d[a][b]);
	}
}