#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	printf("PERFECTION OUTPUT\n");
	int n;
	while (scanf("%d", &n), n)
	{
		int sum = 0;
		for (int i = 1; i < n; i++)
		{
			if (n % i == 0)
				sum += i;
		}

		if (sum > n)
			printf("%5d  ABUNDANT\n", n);
		else if (sum == n)
			printf("%5d  PERFECT\n", n);
		else
			printf("%5d  DEFICIENT\n", n);
	}
	printf("END OF OUTPUT\n");
}