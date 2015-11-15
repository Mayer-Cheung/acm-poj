#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 105;

int mp[MAXN][MAXN];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			mp[i][j] = i == j? 1 : 0;

	int a, b;
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d", &a, &b);
		mp[a][b] = 1;
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				mp[i][j] = mp[i][j] | (mp[i][k] & mp[k][j]);

	int degree[MAXN];
	memset(degree, 0, sizeof(degree));
	int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i != j)
				if (mp[i][j])
				{
					degree[i]++;
					degree[j]++;
				}

	for (int i = 1; i <= n; i++)
		if (degree[i] == n - 1)
			ans++;

	printf("%d\n", ans);
}