#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[4005], b[4005], c[4005], d[4005];
int cd[4005*4005];
int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cd[i * n + j] = c[i] + d[j];
			}
		}
		sort(cd, cd + n * n);
		long long res = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int x = -(a[i] + b[j]);
				res += upper_bound(cd, cd + n * n, x) - lower_bound(cd, cd + n * n, x);
			}
		}
		printf("%lld\n", res);
	}
}