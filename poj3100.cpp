#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int cal(int b, int n, int a)
{
	return abs(b - pow(a, n));
}

int main()
{
	int b, n;
	while (scanf("%d%d", &b, &n) && b + n)
	{
		int a = 1;
		int current_gap = 1e9;
		while (true)
		{
			if (cal(b, n, a) < current_gap)
			{
				current_gap = cal(b, n, a);
				a++;
			}
			else
				break;
		}
		printf("%d\n", a - 1);
	}
}