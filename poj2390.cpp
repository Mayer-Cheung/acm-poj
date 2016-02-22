#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int r, m, y;
	scanf("%d%d%d", &r, &m, &y);
	double res = (double)m;
	double rate = (r + 100) / 100.0;
	for (int i = 0; i < y; i++)
	{
		res *= rate;
	}
	printf("%d\n", (int)res);
} 