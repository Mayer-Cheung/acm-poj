#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 1010;
int dp[MAXN], a[MAXN];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		dp[i] = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++)
			if (a[j] < a[i])
				dp[i] = max(dp[i], dp[j] + 1);
	int los = 0;
	for (int i = 0; i < n; i++)
		los = max(los, dp[i]);
	printf("%d\n", los);
}