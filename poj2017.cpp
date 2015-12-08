#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int n;
	while (scanf("%d", &n) && n != -1)
	{
		int sum = 0, last = 0;
		for (int i = 0; i < n; i++)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			sum += a * (b - last);
			last = b;
		}
		printf("%d miles\n", sum);
	}
}