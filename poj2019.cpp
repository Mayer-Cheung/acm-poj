#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[255][255];
int main()
{
	int n, b, k;
	scanf("%d%d%d", &n, &b, &k);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);

	int row, col;
	for (int t = 1; t <= k; t++)
	{
		scanf("%d%d", &row, &col);
		int max_t = a[row][col], min_t = a[row][col];
		for (int i = 0; i < b; i++)
		{
			for (int j = 0; j < b; j++)
			{
				max_t = max_t > a[i + row][j + col] ? max_t : a[i + row][j + col];
				min_t = min_t < a[i + row][j + col] ? min_t : a[i + row][j + col];
			}
		}
		printf("%d\n", max_t - min_t);
	}
}