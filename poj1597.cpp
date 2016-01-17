#include <iostream>
#include <cstdio>

using namespace std;

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main()
{
	int a, n;
	while (scanf("%d%d", &a, &n) != EOF)
	{
		if (gcd(n, a) == 1)
			printf("%10d%10d    Good Choice\n\n", a, n);
		else
			printf("%10d%10d    Bad Choice\n\n", a, n);
	}
}