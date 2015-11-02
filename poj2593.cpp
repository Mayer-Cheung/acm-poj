#include <iostream>
#include <cstdio>
using namespace std;
int a[100005], lft[100005], rgt[100005];
int main()
{
	int n;
	while (scanf("%d", &n), n)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}

		lft[0] = a[0];
		for (int i = 1; i < n; i++)
			if (lft[i - 1] < 0)
				lft[i] = a[i];
			else
				lft[i] = lft[i - 1] + a[i];

		for (int i = 1; i < n; i++)
			lft[i] = lft[i] > lft[i - 1] ? lft[i] : lft[i - 1];

		rgt[n - 1] = a[n - 1];
		for (int i = n - 2; i >= 0; i--)
			if (rgt[i + 1] < 0)
				rgt[i] = a[i];
			else
				rgt[i] = rgt[i + 1] + a[i];

		for (int i = n - 2; i >= 0; i--)
			rgt[i] = rgt[i + 1] > rgt[i] ? rgt[i + 1] : rgt[i];

		int res = -99999999;
		for (int i = 1; i < n; i++)
			res = res > (lft[i - 1] + rgt[i]) ? res : lft[i - 1] + rgt[i];
		printf("%d\n", res);
	}
}