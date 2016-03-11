#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	int sum_a, sum_b;
	sum_a = sum_b = 0;
	while (a)
	{
		sum_a += a % 10;
		a /= 10;
	}
	while (b)
	{
		sum_b += b % 10;
		b /= 10;
	}
	printf("%d\n", sum_a * sum_b);
}