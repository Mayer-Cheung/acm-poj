#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 25;

int n, B, s;
int v[MAXN], dp[MAXN * 1000000];

int solve()
{
	for (int i = 0; i <= s; i++)
		dp[i] = INF;

	dp[0] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = s; j >= v[i]; j--)
			dp[j] = min(dp[j], dp[j - v[i]] + v[i]);

	int ans = INF;
	for (int i = B; i <= s; i++)
		if (dp[i] >= B)
			ans = min(ans, dp[i]);
	return ans - B;
}

int main()
{
	scanf("%d%d", &n, &B);
	s = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &v[i]);
		s += v[i];
	}
	printf("%d\n", solve());
}