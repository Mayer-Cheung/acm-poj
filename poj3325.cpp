#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 105;
int a[MAXN];

int main()
{
	int n;
	while (scanf("%d", &n), n)
	{
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		sort(a, a + n);
		int sum = 0;
		for (int i = 1; i < n - 1; i++)
			sum += a[i];
		printf("%d\n", sum / (n - 2));
	}
}