#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 25;
int a[MAXN][MAXN];

int main()
{
	int n, s;
	scanf("%d%d", &n, &s);
	memset(a, 0, sizeof(a));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			a[j][i] = s;
			s++;
			if (s > 9)
				s = 1;
		}
	}
	bool flag = true;
	for (int i = 1; i <= n; i++)
	{
		flag = true;
		for (int j = 1; j <= n; j++)
		{
			if (flag)
			{
				if (a[i][j] == 0)
					printf(" ");
				else
					printf("%d", a[i][j]);
				flag = false;
			}
			else
			{
				if (a[i][j] == 0)
					printf("  ");
				else
					printf(" %d", a[i][j]);
			}
		}
		printf("\n");
	}
}