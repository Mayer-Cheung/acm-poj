#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 105;

int mp[MAXN][MAXN];
int in[MAXN], out[MAXN];

int main()
{
	int t, n, m, a, b;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				mp[i][j] = i == j? 1 : 0;

		memset(in, 0, sizeof(in));
		memset(out, 0, sizeof(out));
		for (int i = 1; i <= m; i++)
		{
			scanf("%d%d", &a, &b);
			mp[a][b] = 1;
		}

		for (int k = 1; k <= n; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					mp[i][j] = mp[i][j] | (mp[i][k] & mp[k][j]);

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (i != j)
					if (mp[i][j])
					{
						out[i]++;
						in[j]++;
					}

		int ans = 0, limit = (n + 1) / 2;
		for (int i = 1; i <= n; i++)
		{
			if (in[i] >= limit || out[i] >= limit)
				++ans;
		}
		printf("%d\n", ans);
	}
}