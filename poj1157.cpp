#include <iostream>
#include <cstdio>
using namespace std;
int a[105][105];
int dp[105][105];
int main()
{
	int f, v;
	scanf("%d%d", &f, &v);
	for (int i = 0; i < f; i++)
		for (int j = 0; j < v; j++)
			scanf("%d", &a[i][j]);

	dp[0][0] = a[0][0];
	for (int i = 1; i < v; i++)
		dp[0][i] = max(dp[0][i - 1], a[0][i]);
	for (int i = 1; i < f; i++)
		for (int j = i; j < v; j++)
			dp[i][j] = max(dp[i - 1][j - 1] + a[i][j], dp[i][j - 1]);

	printf("%d\n", dp[f - 1][v - 1]);
}