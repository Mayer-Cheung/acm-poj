#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	int ak, bk;
	double x = (1 + sqrt(5)) / 2;
	while (scanf("%d%d", &ak, &bk) != EOF)
	{
		if (ak > bk)
			swap(ak, bk);
		int n = bk - ak;
		if (ak == (int) (n * x))
			printf("0\n");
		else
			printf("1\n");
	}
}