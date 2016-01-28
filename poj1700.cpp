#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1005;
int a[MAXN];

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, total = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		sort(a + 1, a + n + 1);

		while (n)
		{
			if (n == 1)
			{
				total += a[1];
				break;
			}
			if (n == 2)
			{
				total += a[2];
				break;
			}
			if (n == 3)
			{
				total += a[1] + a[2] + a[3];
				break;
			}
			else
			{
				total += min(a[1] + 2 * a[2] + a[n], 2 * a[1]+ a[n - 1] + a[n]);
				n -= 2;
			}
		}
		printf("%d\n", total);
	}
}