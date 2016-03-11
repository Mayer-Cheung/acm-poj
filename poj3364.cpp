#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int n, m, c;
	while (scanf("%d%d%d", &n, &m, &c) && n + m + c)
	{
		int sum = 0;
		for (int i = 0; i <= m - 8; i++)
		{
			sum += (n - 8 + !c) / 2 + c;
			c = !c;
		}
		printf("%d\n", sum);
	}
}

int main()
{
	int n, m, c;
	while (scanf("%d%d%d", &n, &m, &c) && n + m + c)
	{
		int sum = 0;
		int sum2 = (n - 8 + 1) / 2;
		int sum1 = (n - 8) / 2 + 1;
		if (c == 1)
		{
			sum += sum1 * ((m - 6) / 2);
			sum += sum2 * ((m - 7) / 2);
		}
		else
		{
			sum += sum1 * ((m - 7) / 2);
			sum += sum2 * ((m - 6) / 2);
		}
		printf("%d\n", sum);
	}
}