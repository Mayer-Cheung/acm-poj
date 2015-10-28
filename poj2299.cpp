#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
struct Node
{
	int val, pos;
	bool operator <(const Node &a) const
	{
		return val < a.val;
	}
}a[500010];
int c[500010], b[500010], n;
int lowbit(int n)
{
	return n & (-n);
}
void update(int x, int num)
{
	while (x <= n)
	{
		c[x] += num;
		x += lowbit(x);
	}
}
long long sum(int x)
{
	long long s = 0;
	while (x > 0)
	{
		s += c[x];
		x -= lowbit(x);
	}
	return s;
}
int main()
{
	while (scanf("%d", &n), n)
	{
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i].val);
			a[i].pos = i;
		}
		sort(a + 1, a + 1 + n);
		for (int i = 1; i <= n; i++)
			b[a[i].pos] = i;
		memset(c, 0, sizeof(c));
		long long ans = 0;
		for (int i = 1; i <= n; i++)
		{
			update(b[i], 1);
			ans += i - sum(b[i]);
		}
		printf("%lld\n", ans);
	}
}