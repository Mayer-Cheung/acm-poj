#include <iostream>
#include <cstdio>

using namespace std;

int calc(int k, int b)
{
	int sum = 0;
	while (k)
	{
		sum += k % b;
		k /= b;
	}
	return sum;
}

int main()
{
	for (int i = 2992; i < 10000; i++)
	{
		int a = calc(i, 10);
		int b = calc(i, 12);
		int c = calc(i, 16);
		if (a == b && b == c)
			printf("%d\n", i);
	}
}