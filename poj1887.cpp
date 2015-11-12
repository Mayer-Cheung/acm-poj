#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;

const int MAXN = 200005;
const int INF = 1e8;

int n, g[MAXN], a[MAXN];

int main()
{
	int t = 0;
	while (scanf("%d", &a[1]) == 1 && a[1] != -1)
	{
		if (t > 0)
			printf("\n");
		n = 2;
		while (scanf("%d", &a[n]) == 1 && a[n] != -1)
		{
			n++;
		}
		n--;

		reverse(a + 1, a + n + 1);
		for (int i  = 1; i <= n; i++)
			g[i] = INF;

		int ans = 0;

		for (int i = 1; i <= n; i++)
		{
			int k = lower_bound(g + 1, g + 1 + n, a[i]) - g;
			g[k] = a[i];
			ans = max(ans, k);
		}
		printf("Test #%d:\n  maximum possible interceptions: %d\n",++t,ans);
	}
}