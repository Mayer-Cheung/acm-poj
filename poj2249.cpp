#include <iostream>
#include <cstdio>

using namespace std;

long long C(int a, int b)
{
	long long pro = 1;
	for (int i = a; i >= a - b + 1; i--)
	{
		pro = pro * i;
		pro = pro / (a - i + 1);
	}
	return pro;
}

int main()
{
	int a, n;
	while (scanf("%d%d", &a, &n) && a + n)
		printf("%lld\n", C(a, min(n, a - n)));
}