#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1005;
int a[MAXN], n;

int count()
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				sum++;
			}
		}
	}
	return sum;
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int index = 1; index <= t; index++)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);

		printf("Scenario #%d:\n", index);
		printf("%d\n\n", count());
	}
}