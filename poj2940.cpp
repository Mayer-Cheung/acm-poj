#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	int n;
	while (scanf("%d", &n), n)
	{
		long long sum = 0, now = 0;
		for (int i = 0; i < n; i++)
		{
			long long temp;
			scanf("%lld", &temp);
			sum += now > 0 ? now : -now;
			now += temp;
		}
		printf("%lld\n", sum);
	}
}