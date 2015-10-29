#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	while (scanf("%d", &n), n)
	{
		int day = 0, sum = 0, i;
		for (i = 1; day + i <= n; i++)
		{
			day += i;
			sum += i * i;
		}
		sum += (n - day) * i;
		printf("%d %d\n", n, sum);
	}
}