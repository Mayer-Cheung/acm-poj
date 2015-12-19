#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a[505][105];
int main()
{
	int n, d;
	while (scanf("%d%d", &n, &d) && n + d != 0)
	{
		memset(a, 0, sizeof(a));
		for (int i = 0; i < d; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &a[i][j]);

		bool flag = false;
		for (int i = 0; i < n; i++)
		{
			int sum = 0;
			for (int j = 0; j < d; j++)
				sum += a[j][i];
			if (sum == d)
			{
				flag = true;
				break;
			}
		}
		if (flag)
			printf("yes\n");
		else
			printf("no\n");
	}
}