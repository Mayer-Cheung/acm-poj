#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
struct Point
{
	int x, y;	
}p[705];

int main()
{
	int n;
	while (scanf("%d", &n), n)
	{
		for (int i = 0; i < n; i++)
			scanf("%d%d", &p[i].x, &p[i].y);
		int ans = 0, tans;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				tans = 2;
				for (int k = j + 1; k < n; k++)
				{
					if ((p[k].y - p[j].y) * (p[j].x - p[i].x) == (p[j].y - p[i].y) * (p[k].x - p[j].x))
						tans++;
				}
				ans = tans > ans ? tans : ans;
			}
		}
		printf("%d\n", ans);
	}
}

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

double x[705], y[705], d[705];
const int INF = 1 << 30;
int main()
{
	int n, i, j, k;
	int ans, cnt;
	while (scanf("%d", &n), n)
	{
		for (i = 0; i < n; i++)
			scanf("%lf%lf", &x[i], &y[i]);

		ans = 1;
		for (i = 0; i < n - 1; i++)
		{
			for (j = i + 1, k = 0; j < n; j++, k++)
				d[k] = (x[j] == x[i]) ? INF : (y[j] - y[i]) / (x[j] - x[i]);
			sort(d, d + k);
			cnt = 1;
			for (j = 1; j < k; j++)
			{
				if (fabs(d[j] - d[j - 1] < 1e-9))
				{
					cnt++;
					ans = max(cnt, ans);
				}
				else
					cnt = 1;
			}
		}
		printf("%d\n", ans + 1);
	}
}