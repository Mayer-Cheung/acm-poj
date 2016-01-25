#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

const int MAXN = (1 << 7) + 5;
double table[MAXN][MAXN];
double dp[8][MAXN];

int main()
{
	int n;
	while (scanf("%d", &n) && n != -1)
	{
		int num = 1 << n;
		for (int i = 0; i < num; i++)
			for (int j = 0; j < num; j++)
				scanf("%lf", &table[i][j]);

		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < num; i++)
			dp[0][i] = 1;

		for (int i = 1; i <= n; i++)
			for (int j = 0; j < num; j++)
				for (int k = 0; k < num; k++)
					if ((j >> (i - 1) ^ 1) == (k >> (i - 1)))
						dp[i][j] += dp[i - 1][j] * dp[i - 1][k] * table[j][k];

		double max = -1;
		int index;
		for (int i = 0; i < num; i++)
			if (max < dp[n][i])
			{
				index = i;
				max = dp[n][i];
			}
		printf("%d\n", index + 1);
	}
}