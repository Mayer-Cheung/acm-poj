#include <iostream>
#include <cstdio>
using namespace std;
int cal(int n)
{
	int sum = 0;
	while (n != 1)
	{
		if (n % 2 == 0)
			n /= 2;
		else
			n = 3 * n + 1;
		sum++;
	}
	return sum;
}
int main()
{
	int a, b;
	while (scanf("%d%d", &a, &b) != EOF)
	{
		int max = 0;
		for (int i = a; i <= b; i++)
			if (max < cal(i))
				max = cal(i);
		printf("%d %d %d\n", a, b, max);
	}
}