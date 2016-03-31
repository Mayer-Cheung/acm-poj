#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int n, f;
const int MAXN = 10005;
const double pi = acos(-1.0);
const double esp = 1e-5;
double a[MAXN];

bool C(double x)
{
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		num += (int)(pi * a[i] * a[i] / x);
	}
	return num >= f + 1;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &n, &f);
		for (int i = 0; i < n; i++)
			scanf("%lf", &a[i]);
		double lb = 0.0, ub = 1e9;
		for (int i = 0; i < 100; i++)
		{
			double mid = (lb + ub) / 2;
			if (C(mid))
				lb = mid;
			else
				ub = mid;
		}
		printf("%.4lf\n", ub);
	}

}