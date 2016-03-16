#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 105;
long dp[MAXN][MAXN];

long cal(int n, int m)
{
	if (dp[n][m] != 0)
		return dp[n][m];
	else if (n == m)
		return 1;
	return dp[n][m] = cal(n - 1, m) + cal(n - 1, m - 1);
}

int main()
{
	int n, m;
	while (true)
	{
		scanf("%d%d", &n, &m);
		if (n == 0 && m == 0)
			break;
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i <= n; i++)
			dp[i][0] = 1;
		printf("%d things taken %d at a time is %ld exactly.\n", n, m, cal(n, m));
	}
}