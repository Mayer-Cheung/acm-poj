#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const double pi = 3.141592653589793;

double distance(double x1, double y1, double x2, double y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main()
{
	double x1, x2, x3, y1, y2, y3, p, s, a, b, c, l;
	while (scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3) != EOF)
	{
		a = distance(x1, y1, x2, y2);
		b = distance(x2, y2, x3, y3);
		c = distance(x1, y1, x3, y3);

		p = (a + b + c) / 2;

		s = sqrt(p * (p - a) * (p - b) * (p - c));

		l = (a * b * c) / (2 * s) * pi;
		printf("%.2lf\n", l);
	}
}