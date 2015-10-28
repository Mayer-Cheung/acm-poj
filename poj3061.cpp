//  method 1
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n, s;
int a[100010];
int sum[100010];
void solve()
{
	for (int i = 0; i < n; i++)
		sum[i + 1] = sum[i] + a[i];
	if (sum[n] < s)
	{
		printf("0\n");
		return;
	}
	int res = n;
	for (int i = 0; sum[n] - sum[i] >= s; i++)
	{
		int t = lower_bound(sum + i, sum + n, sum[i] + s) - sum;
		res = min(t - i, res);
	}
	printf("%d\n", res);
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		memset(sum, 0, sizeof(sum));
		scanf("%d%d", &n, &s);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		solve();
	}
}
//  mothod 2
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n, s;
int a[100010];
void solve()
{
	int b = 0, e = 0, sum = 0, res = n + 1;
	for(;;)
	{
		while (sum < s && e < n)
		{
			sum += a[e];
			e++;
		}
		if (sum < s)
		{
			break;
		}
		res = min(e - b, res);
		sum -= a[b++];
	}
	if (res > n)
	{
		res = 0;
	}
	printf("%d\n", res);
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &n, &s);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		solve();
	}
}