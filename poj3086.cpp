#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 305;
int a[MAXN];

int main()
{
	memset(a, 0, sizeof(a));
	for (int i = 1; i < MAXN; i++)
		a[i] += a[i - 1] + i;
	int t;
	scanf("%d", &t);
	for (int test = 1; test <= t; test++)
	{
		int n;
		scanf("%d", &n);
		int sum = 0;
		for (int i = 1; i <= n; i++)
			sum += (i * a[i + 1]);
		printf("%d %d %d\n", test, n, sum);
	}
}