#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int calculate(double n)
{
	int ans = 1;
	double sum = 0;
	while (sum < n)
	{
		sum += 1.0 / (ans + 1);
		ans++;
	}
	return ans - 1;
}
int main()
{
	double n;
	while (scanf("%lf", &n) && n != 0.00)
	{
		printf("%d card(s)\n", calculate(n));
	}
}