#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>

using namespace std;

const double esp = 1e-8;

int main()
{
	double L, N, C;
	double s, h, r;
	double low, high, mid, ans;
	while (scanf("%lf%lf%lf", &L, &N, &C) != EOF)
	{
		if (L < 0 && N < 0 && C < 0)
			break;
		low = 0;
		high = L / 2;
		s = (1 + N * C) * L;
		while (high - low > esp)
		{
			mid = (low + high) * 0.5;
			r = (4 * mid * mid + L * L) / (8 * mid);
			if (2 * r * asin(L / (2 * r)) < s)
			{
				low = mid;
			}
			else
			{
				high = mid;
			}
		}
		printf("%.3lf\n", mid);
	}
}