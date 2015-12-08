#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	while (n--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if (a == b && a % 2 == 0)
		{
			printf("%d\n", a * 2);
			continue;
		}
		if (a == b && a % 2 == 1)
		{
			printf("%d\n", a * 2 - 1);
			continue;
		}
		if (a - b == 2 && b % 2 == 0)
		{
			printf("%d\n", 2 * (b + 1));
			continue;
		}
		if (a - b == 2 && b % 2 == 1)
		{
			printf("%d\n", b * 2 + 1);
			continue;
		}
		printf("No Number\n");
	}
}