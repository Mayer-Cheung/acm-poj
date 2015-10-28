#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int dp[20][15005];
int c[20], g[20];
int main()
{
	int C, G;
	scanf("%d%d", &C, &G);
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= C; i++)
	{
		scanf("%d", &c[i]);
	}
	for (int i = 1; i <= G; i++)
	{
		scanf("%d", &g[i]);
	}

	dp[0][7500] = 1;
	//  notice the order of the state transforming, the order of the G[i], C[q] cannot be reversed
	for (int i = 1; i <= G; i++)
	{
		for (int j = 1; j <= 15000; j++)
		{
			if (dp[i - 1][j])
			for (int q = 1; q <= C; q++)
			{
				dp[i][j + c[q] * g[i]] += dp[i - 1][j];
			}
		}
	}
	printf("%d\n", dp[G][7500]);
}