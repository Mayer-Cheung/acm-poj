#include <iostream>
#include <cstdio>

using namespace std;

int a[20];

int main()
{
	int n, i;
	while (scanf("%d", &n) && n != -1)
	{
		a[0] = n;
		i = 1;
		while (true)
		{
			scanf("%d", &n);
			if (n == 0)
				break;
			a[i++] = n;
		}
		int cnt = 0;
		for (int x = 0; x < i; x++)
		{
			for (int y = 0; y < i; y++)
			{
				if (a[x] == a[y] * 2)
					cnt++;
			}
		}
		printf("%d\n", cnt);
	}
}