#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a[105];
int main()
{
	int test;
	scanf("%d", &test);
	while (test--)
	{
		memset(a, 0, sizeof(a));
		int n;
		scanf("%d", &n);

		for (int i = 1; i <= n; i++)
		{
			for (int j = i; j <= n; j += i)
				a[j] = !a[j];
		}

		int sum = 0;
		for (int i = 1; i <= n; i++)
			sum += a[i];
		printf("%d\n", sum);
	}
}