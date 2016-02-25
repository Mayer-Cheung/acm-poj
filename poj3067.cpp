#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
const int MAXN = 1000005;

P p[MAXN];
ll bit[1005];

int n, m, k;

inline int lowbit(int x)
{
	return x & -x;
}

void add(int pos, int n)
{
	while (pos <= m)
	{
		bit[pos] += n;
		pos += lowbit(pos);
	}
}

ll sum(int pos)
{
	ll sum = 0;
	while (pos > 0)
	{
		sum += bit[pos];
		pos -= lowbit(pos);
	}
	return sum;
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int kase = 1; kase <= t; kase++)
	{
		memset(bit, 0, sizeof(bit));
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 0; i < k; i++)
			scanf("%d%d", &p[i].first, &p[i].second);
		sort(p, p + k);
		ll ans = 0;
		for (int i = 0; i < k; i++)
		{
			ans += i - sum(p[i].second);
			add(p[i].second, 1);
		}
		printf("Test case %d: %lld\n", kase, ans);
	}
}