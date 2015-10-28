#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 26;
int n, h, t[MAXN], d[MAXN], f[MAXN], F[MAXN], ans[MAXN], ANS[MAXN];
int main()
{
	int max, sum, p, k, i, j, time;
	while (scanf("%d", &n), n)
	{
		scanf("%d", &h);
		h *= 12;
		for (i = 0; i < n; i++)
			scanf("%d", &F[i]);
		for (i = 0; i < n; i++)
			scanf("%d", &d[i]);
		for (i = 1; i < n; i++)
		{
			scanf("%d", &time);
			t[i] = t[i - 1] + time;
		}
		memset(ANS, 0, sizeof(ANS));
		//  done with input

		for (max = 0, i = 1; i <= n; i++)
		{
			memset(ans, 0, sizeof(ans));
			memcpy(f, F, sizeof(F));
			for (j = 0, sum = 0; j < h - t[i - 1]; j++)
			{
				for (p = 0, k = 1; k < i; k++)
				{
					if (f[k] > f[p])
						p = k;
				}
				if (f[p] <= 0)
				{
					ans[0] += h - t[i - 1] - j;
					break;
				}
				sum += f[p];
				f[p] -= d[p];
				ans[p]++;
			}
			if (sum > max)
			{
				max = sum;
				memcpy(ANS, ans, sizeof(ans));
			}
			if (sum == max)
			{
				for (j = 0; j < i; j++)
					if (ans[j] != ANS[j])
						break;
				if (ans[j] > ANS[j])
					memcpy(ANS, ans, sizeof(ans));
			}
		}
		for (int i = 0; i < n - 1; i++)
		{
			printf("%d, ", ANS[i] * 5);
		}
		printf("%d\n", ANS[n - 1] * 5);
		printf("Number of fish expected: %d\n\n", max);
	}
}