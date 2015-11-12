#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 40005;
const int INF = 1e9;

int n, a[MAXN], g[MAXN];

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			g[i] = INF;
		}

		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			int k = lower_bound(g + 1, g + 1 + n, a[i]) - g;
			g[k] = a[i];
			ans = max(ans, k);
		}
		printf("%d\n", ans);
	}
}