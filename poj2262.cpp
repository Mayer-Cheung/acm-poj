#include <iostream>
#include <cstdio>

using namespace std;

int prime[80000];
bool is_prime[1000005];

int sieve(int n)
{
	int p = 0;
	for (int i = 0; i <= n; i++)
		is_prime[i] = true;
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= n; i++)
	{
		if (is_prime[i])
		{
			prime[p++] = i;
			for (int j = 2 * i; j <= n; j += i)
				is_prime[j] = false;
		}
	}
	return p;
}

int main()
{
	int p = sieve(1000000);
	int n;
	while (scanf("%d", &n), n)
	{
		for (int i = 0;; i++)
		{
			if (is_prime[n - prime[i]])
			{
				printf("%d = %d + %d\n", n, prime[i], n - prime[i]);
				break;
			}
		}
	}
}