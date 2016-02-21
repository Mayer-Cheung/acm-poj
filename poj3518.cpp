#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1300000;
int prime[MAXN];
int order[MAXN], num = 0;

void init()
{
	for (int i = 2; i * i <= MAXN; i++)
	{
		if (prime[i])
		{
			for (int j = 2 * i; j < MAXN; j += i)
			{
				prime[j] = 0;
			}
		}
	}
	for (int i = 2; i < MAXN; i++)
	{
		if (prime[i])
		{
			prime[i] = 0;
			order[++num] = i;
		}
		else
			prime[i] = num;
	}
}

int main()
{
	int n;
	memset(order, 0, sizeof(order));
	memset(prime, 1, sizeof(prime));
	init();
	while (scanf("%d", &n) && n)
	{
		if (!prime[n])
			printf("0\n");
		else
			printf("%d\n", order[prime[n] + 1] - order[prime[n]]);
	}
}