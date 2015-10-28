#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int n, k;
struct jewels
{
	double c, v, w;
	int id;
}a[100010];
bool cmp(const jewels& a, const jewels& b)
{
	return a.c > b.c; 
} 
bool check(double mid)
{
	for (int i = 0; i < n; i++) {;
		a[i].c = a[i].v - mid * a[i].w;
	}
	sort(a, a + n, cmp);
	double sum = 0;
	for (int i = 0; i < k; i++)
		sum += a[i].c;
	return sum > 0;
}
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i)
	{
		scanf("%lf%lf", &a[i].v, &a[i].w);
		a[i].id = i + 1;
	}
	double lb = 0, ub = 1e8;
	while (ub - lb > 1e-6)
	{
		double mid = (ub + lb) / 2;
		if (check(mid))
			lb = mid;
		else
			ub = mid;		
	}
	printf("%d", a[0].id);
	for (int i = 1; i < k; i++)
		printf(" %d", a[i].id);
}