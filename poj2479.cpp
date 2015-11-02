#include <iostream>
#include <cstdio>
using namespace std;
int a[50005], lft[50005], rght[50005];
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);

		lft[0] = a[0];
		for (int i = 1; i < n; i++)
			if (lft[i - 1] < 0)
				lft[i] = a[i];
			else
				lft[i] = lft[i - 1] + a[i];
		rght[n - 1] = a[n - 1];
		for (int i = 1; i < n; i++)
			lft[i] = lft[i] > lft[i - 1] ? lft[i] : lft[i - 1];

		for (int i = n - 2; i >= 0; i--)
			if (rght[i + 1] < 0)
				rght[i] = a[i];
			else
				rght[i] = rght[i + 1] + a[i];

		for (int i = n - 2; i >= 0; i--)
			rght[i] = rght[i + 1] > rght[i] ? rght[i + 1] : rght[i];
		int res = -999999999;
		for (int i = 1; i < n; i++)
			res = res > (lft[i - 1] + rght[i]) ? res : lft[i - 1] + rght[i]; 
		printf("%d\n", res);
	}
}