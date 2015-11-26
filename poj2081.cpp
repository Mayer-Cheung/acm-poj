#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 500005;

int dp[MAXN], flag[5 * MAXN];

void init()
{
	for (int i = 1; i < 500002; i++)
	{
		if (dp[i - 1] - i > 0 && flag[dp[i - 1] - i] == false)
			dp[i] = dp[i - 1] - i;
		else
			dp[i] = dp[i - 1] + i;

		flag[dp[i]] = true;
	}
}

int main()
{
	int n;
	dp[0] = 0;
	memset(flag, false, sizeof(flag));
	flag[0] = true;
	init();
	while (scanf("%d", &n))
	{
		if (n == -1)
			break;

		printf("%d\n", dp[n]);
	}
}