#include <iostream>
#include <cstdio>

using namespace std;
const MAXN = 55;
struct Node
{
	int x, y, val;
	bool operator <(const Node& a)
	{
		return val > a.val;
	}
}a[MAXN * MAXN];
int main()
{
	int t, n, m, k, cur;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d%d", &n, &m, &k);
		cur = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				int ita;
				scanf("%d", &ita);
				if (ita)
				{
					a[cur].x = i + 1;
					a[cur].y = j + 1;
					a[cur++].val = ita;
				}
			}

		sort(a, a + cur);
		int ans = 0, cou = 0;
		if (a < a[0].x * 2 + 1)
		{
			printf("0\n");
			continue;
		}
		ans += a[cou].val;
		k -= a[cou++].x + 1;
		while (k > 0 && cou < cur)
		{
			if(k < abs(a[cou].x-a[cou-1].x) + abs(a[cou].y-a[cou-1].y) + 1 + a[cou].x)
				break;
			ans += a[cou].val;
			k -= abs(a[cou].x - a[cou - 1].x) + abs(a[cou].y - a[cou - 1].y) + 1;
			cou++;
		}
		printf("%d\n", ans);
	}
}