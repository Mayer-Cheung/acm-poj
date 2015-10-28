#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int num[100017], f[100017], MAX[100017][20];
int n;
int ask(int l, int r)
{
	if (l > r)
		return 0;
	int k = log(r - l + 1) / log(2);
	return max(MAX[l][k], MAX[r + 1 - (1 << k)][k]);
}
void init()
{
	for (int i = 1; i <= n; i++)
	{
		MAX[i][0] = f[i];
	}
	for (int j = 1; j <= int(log(n) / log(2)); j++)
		for (int i = 1; i + (1 << j) - 1 <= n; i++)
			MAX[i][j] = max(MAX[i][j - 1], MAX[i + (1 << j - 1)][j - 1]);
}
int main()
{
	int a, b, q;
	while (scanf("%d", &n), n)
	{
		scanf("%d", &q);
		for (int i = 1; i <= n; i++)
			scanf("%d", &num[i]);
		for (int i = 1; i <= n; i++)
		{
			if (i == 1)
			{
				f[i] = 1;
				continue;
			}
			if (num[i] == num[i - 1])
				f[i] = f[i - 1] + 1;
			else
				f[i] = 1;
		}
		init();
		for (int i = 1; i <= q; i++)
		{
			scanf("%d%d", &a, &b);
			int t = a;
			while (t <= b && num[t] == num[t - 1])
				t++;
			int cnt = ask(t, b);
			printf("%d\n", max(t - a, cnt));
		}
	}
}