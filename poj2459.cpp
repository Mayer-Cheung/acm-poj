#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int cow[2005];

int main()
{
	int c, f1, f2, d;
	scanf("%d%d%d%d", &c, &f1, &f2, &d);
	memset(cow, 0, sizeof(cow));
	for (int i = 0; i < c; i++)
	{
		int m, n;
		scanf("%d%d", &m, &n);
		for (int j = m; j <= n; j++)
			cow[j]++;
	}
	f1 -= f2;
	for (int i = d; i >= 1; i--)
	{
		f1 -= cow[i];
		if (f1 == 0)
		{
			printf("%d\n", i);
			break;
		}
	}
}