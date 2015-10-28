#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int n, k;
double a[1010], b[1010];
double c[1010];
bool check(double mid)
{
	for (int i = 0; i < n; i++)
		c[i] = 100 * a[i] - mid * b[i];
	sort(c, c + n);
	double sum = 0;
	for (int i = k; i < n; i++)
		sum += c[i];
	return sum > 0;
}
int main()
{
	while (scanf("%d%d", &n, &k) != EOF)
	{
		if (n == 0 && k == 0)
			break;
		for (int i = 0; i < n; ++i)
		{
			scanf("%lf", &a[i]);
		}
		for (int i = 0; i < n; ++i)
		{
			scanf("%lf", &b[i]);
		}
		double lb = 0, ub = 100;
		while (ub - lb > 1e-10)
		{
			double mid = (ub + lb) / 2;
			if (check(mid))
				lb = mid;
			else
				ub = mid;		
		}
		printf("%.0f\n", lb);
	}
}