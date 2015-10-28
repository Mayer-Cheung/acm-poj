#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int a[50005];
int dp_min[50005][18], dp_max[50005][18];
int n, q;
int l, r;
void init()
{
	for (int i = 1; i <= n; i++)
	{
		dp_min[i][0] = a[i];
		dp_max[i][0] = a[i];
	}
	for (int j  = 1; j <= int(log(n) / log(2)); j++)
	{
		for (int i = 1; i + (1 << j) - 1 <= n; i++)
		{
			dp_min[i][j] = min(dp_min[i][j - 1], dp_min[i + (1 << j - 1)][j - 1]);
			dp_max[i][j] = max(dp_max[i][j - 1], dp_max[i + (1 << j - 1)][j - 1]);
		}
	}
}
int ask_max(int l, int r)
{
	int k = int(log(r - l + 1) / log(2));
	return max(dp_max[l][k], dp_max[r + 1 - (1 << k)][k]);
}
int ask_min(int l, int r)
{
	int k = int(log(r - l + 1) / log(2));
	return min(dp_min[l][k], dp_min[r + 1 - (1 << k)][k]);
}
int main()
{
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	init();
	while (q--)
	{
		scanf("%d%d", &l, &r);
		printf("%d\n", ask_max(l, r) - ask_min(l, r));
	}
}