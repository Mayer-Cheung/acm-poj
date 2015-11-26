#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 105;
const int MAXV = 2 * 1e5 + 5;
const int INF = 0x3f3f3f3f;

int dp[MAXV], s[MAXN], f[MAXN], n;

inline int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int mid = 1e5;
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 0; i < n; i++)
			scanf("%d%d", &s[i], &f[i]);

		for (int i = 0; i < MAXV; i++)
			dp[i] = -INF;

		dp[mid] = 0;

		for (int i = 0; i < n; i++)
		{
			if (s[i] > 0)
			{
				for (int j = MAXV; j >= s[i]; j--)
					dp[j] = max(dp[j], dp[j - s[i]] + f[i]);
			}
			else
			{
				for (int j = 0; j < MAXV + s[i]; j++)
					dp[j] = max(dp[j], dp[j - s[i]] + f[i]);
			}
		}

		int ans = 0;

		for (int i = 1e5; i <= 2 * 1e5; i++)
			if (dp[i] >= 0 && dp[i] + i - 1e5 > ans)
				ans = dp[i] + i - 1e5;

		printf("%d\n", ans);
	}
}