#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int fac(int n)
{
	int pro = 1; 
	if (n == 0 || n == 1)
		return 1;
	else
	{
		while (n)
		{
			pro *= n;
			n--;
		}
	}
	return pro;
}
void solve(int n)
{
	double sum = 0;
	for (int i = 0; i <= n; i++)
		sum += (1.0) / (fac(i));
	printf("%d %.9lf\n", n, sum);
}
int main()
{
	printf("n e\n- -----------\n");
	for (int i = 0; i <= 9; i++)
		solve(i);
}