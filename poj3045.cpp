#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct cow
{
	int w, s;
}a[50010];
int n;
bool cmp(const cow& a, const cow& b)
{
	return a.w + a.s > b.w + b.s;
}

int main()
{
	scanf("%d", &n);
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &a[i].w, &a[i].s);
		sum += a[i].w;
	}
	sort(a, a + n, cmp);
	int ans = -600000000;
	for (int i = 0; i < n; i++)
	{
		sum -= a[i].w;
		ans = max(ans, sum - a[i].s);
	}
	printf("%d\n", ans);
}