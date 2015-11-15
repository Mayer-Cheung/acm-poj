#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 105;
const int INF = 1e9; 
int a[MAXN][MAXN];
int x[MAXN];
int main()
{
	int n, num, p, t;
	while (scanf("%d", &n), n)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				a[i][j] = i == j ? 0 : INF;	
			}
		}
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &num);
			for (int j = 1; j <= num; j++)
			{
				scanf("%d%d", &p, &t);
				a[i][p] = t;
			}
		}

		for (int k = 1; k <= n; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					if (a[i][k] < INF && a[k][j] < INF)
						a[i][j] = min(a[i][k] + a[k][j], a[i][j]);

		for (int i = 1; i <= n; i++)
		{
			int temp = a[i][1];
			for (int j = 1; j <= n; j++)
			{
				temp = max(temp, a[i][j]);
			}
			x[i] = temp;
		}

		int ans = INF, mn = -1;
		for (int i = 1; i <= n; i++)
		{
			if (ans > x[i])
			{
				ans = x[i];
				mn = i;
			}
		}
		if (ans == INF)
		{
			printf("disjoint\n");
		}
		else
		{
			printf("%d %d\n", mn, ans);
		}
	}
}