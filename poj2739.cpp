#include <iostream>
#include <cstdio>

using namespace std;

int prime[10005];
bool is_prime[10005];

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
	int p = sieve(10000);
	int n;
	while (scanf("%d", &n), n)
	{
		int cnt = 0;
		for (int i = 0; prime[i] <= n; i++)
		{
			for (int j = i, temp = 0; temp <= n; j++)
			{
				temp += prime[j];
				if (temp == n)
					cnt++;
			}
		}
		printf("%d\n", cnt);
	}
}