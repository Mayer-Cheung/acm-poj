#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
	int n;
	while (scanf("%d", &n) && n)
	{	
		double s, t, m = 9999999;
		while (n--)
		{
			scanf("%lf%lf", &s, &t);
			if (t >= 0.0)
			{
				t += 4500.0 * 3.6 / (s * 1.0);
				if (t - m < 1e-5)
					m = t;
			}
		}
		printf("%.0lf\n", ceil(m));
	}
	return 0;
}