#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 510;
int n, m, a[MAXN];
long long sum;
bool flag[MAXN];

void init()
{
	sum = 0;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		sum += a[i];
	}
}

bool judge(long long lmt)
{
	memset(flag, 0, sizeof(flag));
	int cnt = m;
	long long now = 0;
	for (int i = n; i; i--)
	{
		if ((now + a[i] > lmt) || i < cnt)
		{
			now = a[i];
			cnt--;
			flag[i] = true;
			if (cnt == 0)
				return false;
		}
		else
			now += a[i];
	}
	return true;
}

void work()
{
	long long l = 0, r = sum, mid;
	for (int i = 1; i <= n; i++)
		if (l < a[i])
			l = a[i];
	while (l != r)
	{
		mid = (l + r) >> 1;
		if (judge(mid))
			r = mid;
		else
			l = mid + 1;
	}
	judge(l);
	for (int i = 1; i <= n; i++)
	{
		printf("%d", a[i]);
		if (i < n)
			printf(" ");
		if (flag[i])
			printf("/ ");
	}
	printf("\n");
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		init();
		work();
	}
}