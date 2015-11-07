#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int a[55];

int main()
{
	int test = 1;
	int n;
	while (scanf("%d", &n), n)
	{
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			sum += a[i];
		}

		int avg = sum / n;
		int num = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i] > avg)
				num += a[i] - avg;
		}

		printf("Set #%d\n", test++);
		printf("The minimum number of moves is %d.\n", num);
	}
}