#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int a[105];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= 100; i++)
		a[i] = i * i * i;
	for (int i = 6; i <= n; i++)
		for (int j = 2; j <= n; j++)
			for (int k = j + 1; k <= n; k++)
			{
				if ((a[j] + a[k]) > a[i])
					break;
				for (int l = k + 1; l <= n; l++)
				{
					if (a[j] + a[k] + a[l] > a[i])
						break;
					if (a[i] == a[j] + a[k] + a[l])
						printf("Cube = %d, Triple = (%d,%d,%d)\n", i, j, k, l);
				}
			}
}