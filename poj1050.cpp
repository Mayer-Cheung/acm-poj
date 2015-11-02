#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 105;
int n, temp[MAXN], a[MAXN][MAXN];

inline int arrayMax(int *arr)
{
	int max = 0, dp = 0;
	for (int i = 0; i < n; i++)
		if (dp < 0)
			dp = arr[i];
		else
		{
			dp += arr[i];
			max = dp > max ? dp : max;
		}
	return max;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
	int maxAll = 0, maxOne = 0;
	for (int i = 0; i < n; i++)
	{
		memset(temp, 0, sizeof(temp));
		for (int j = i; j < n; j++)
		{
			for (int k = 0; k < n; k++)
				temp[k] += a[j][k];
			maxOne = arrayMax(temp);
			maxAll = maxOne > maxAll ? maxOne : maxAll;
		}
	}
	printf("%d\n", maxAll);
}