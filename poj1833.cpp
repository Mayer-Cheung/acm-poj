#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int a[1030];

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);

		do
		{
			next_permutation(a, a + n);
		} while (--k);
	
		printf("%d", a[0]);
		for (int i = 1; i < n; i++)
			printf(" %d", a[i]);
		printf("\n");
	}

}