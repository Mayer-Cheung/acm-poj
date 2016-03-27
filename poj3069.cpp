#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1005;
int trp[MAXN];

int main()
{
	int r, n;
	while (true)
	{
		scanf("%d%d", &r, &n);
		if (r == -1 && n == -1)
			break;
		for (int i = 0; i < n; i++)
			scanf("%d", &trp[i]);
		sort(trp, trp + n);
		int cur = 0, ans = 0;
		while (cur < n)
		{
			while (cur < n)
			{
				int s = trp[cur++];
				while (cur < n && trp[cur] <= s + r)
					cur++;
				int p = trp[cur - 1];
				while (cur < n && trp[cur] <= p + r)
					cur++;
				ans++;
			}
		}
		printf("%d\n", ans);
	}
}