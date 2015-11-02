#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
	int n, m = 1000000000;
	int mi, mj, mk;
	scanf("%d", &n);
	for (int i = 1; i <= sqrt(n) + 1; i++)
	{
		if (n % i == 0)
		{
			for (int j = 1; j <= n / i; j++)
			{
				int k = i * j;
				if (n % k == 0)
				{
					k = n / k;
					if (i * j + j * k + k * i < m)
					{
						m = i * j + i * k + j * k;
						mi = i;
						mj = j;
						mk = k;
					}
				}
			}
		}
	}
	printf("%d %d %d\n", mi, mj, mk);
	return 0;
}