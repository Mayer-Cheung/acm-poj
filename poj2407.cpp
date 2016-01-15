#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	long long num, i, n;
	while (scanf("%lld", &n), n)
	{
		num = n;
		for (i = 2; i <= n; i++)
		{
			if (n % i == 0)
			{
				num = (num / i) * (i - 1);
				while (n % i == 0)
					n /= i;
			}
		}
		printf("%lld\n", num);
	}
}