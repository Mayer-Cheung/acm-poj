#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n, m;
int a[100010];
bool check(int mid)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += n - (lower_bound(a, a + n, a[i] + mid) - a);
	}
	return sum > m;
}
int main()
{
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		m = n * (n - 1) / 4;
		sort(a, a + n);
		int lb = 0, ub = a[n - 1] - a[0];
		while (lb <= ub)
		{
			int mid = (lb + ub) >> 1;
			if (check(mid))
				lb = mid + 1;
			else
				ub = mid - 1;
		}
		printf("%d\n", lb - 1);
	}
}