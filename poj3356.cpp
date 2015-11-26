#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1005;

int n, m;
int dp[MAXN][MAXN];
char s1[MAXN], s2[MAXN];

int main()
{
	while (scanf("%d%s", &n, s1) == 2)
	{
		scanf("%d%s", &m, s2);

		for (int i = 0; i <= m; i++)
			dp[0][i] = i;

		for (int i = 0; i <= n; i++)
			dp[i][0] = i;

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
			{
				dp[i][j] = dp[i - 1][j - 1] + (s1[i - 1] == s2[j - 1] ? 0 : 1);
				dp[i][j] = min(dp[i][j], min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
			}
		printf("%d\n", dp[n][m]);
	}
}