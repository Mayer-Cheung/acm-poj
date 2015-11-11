#include <iostream>
#include <cstdio>

using namespace std;

bool is_prime(int n)
{
	if (n == 1 || n == 0)
		return false;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0)
			return false;
	return true;
}

int main()
{
	int a, d, n;
	while (scanf("%d%d%d", &a, &d, &n), a + d + n)
	{
		int sum = a;
		while (n)
		{
			if (is_prime(sum))
				n--;
			sum += d;
		}
		printf("%d\n", sum - d);
	}
}