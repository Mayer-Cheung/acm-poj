#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	int a, b, c, d;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d%d", &a, &b, &c, &d);
		if (a * d == b * c)
			printf("%d %d %d %d %d\n", a, b, c, d, d * b / a);
		else
			printf("%d %d %d %d %d\n", a, b, c, d, d + b - a);
	}
}