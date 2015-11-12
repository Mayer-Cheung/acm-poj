#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 100005;
const int INF = 1e9;

int n, a[MAXN], g[MAXN];

int main()
{
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			g[i] = inf;
		}

		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			int k = lower_bound(g + 1, g + 1 + n, a[i]) - g;
			g[k] = a[i];
			ans = max(k, ans);
		}

		printf("%d\n", ans);
	}
}