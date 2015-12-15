#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 10005;

unsigned g[MAXN];

unsigned sum_of_digits(unsigned n)
{
	if (n < 10)
		return ;
	else
		return (n % 10) + sum_of_digits(n / 10);
}

void generate_sequence(unsigned n)
{
	while (n < MAXN)
	{
		unsigned next = n + sum_of_digits(n);
		if (next >= MAXN || g[next] != next)
			return;
		g[next] = n;
		n = next;
	}
}

int main()
{
	for (unsigned n = 1; n < 10000; n++)
		g[n] = n;

	for (unsigned n = 1; n < 10000; n++)
		generate_sequence(n);

	for (unsigned n = 1; n < 10000; n++)
		if (g[n] == n)
			printf("%u\n", n);
}