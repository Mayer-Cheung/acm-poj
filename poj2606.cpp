#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

double x[205], y[205], d[205];
const int INF = 1 << 30;
int main()
{
	int n, i, j, k;
	int ans, cnt;
	while (scanf("%d", &n) != EOF)
	{
		ans = 1;

		for (i = 0; i < n; i++)
			scanf("%lf%lf", &x[i], &y[i]);
	
		for (i = 0; i < n - 1; i++)
		{
			for (j = i + 1, k = 0; j < n; j++, k++)
				d[k] = (x[j] == x[i]) ? INF : (y[j] - y[i]) / (x[j] - x[i]);
			sort(d, d + k);
	
			cnt = 1;
			for (j = 1; j < k; j++)
			{
				if (fabs(d[j] - d[j - 1]) < 1e-9) 
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