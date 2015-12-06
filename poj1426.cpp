#include <iostream>
#include <cstdio>

using namespace std;
int flag, n;

int dfs(unsigned long long a, int step)
{
	if (flag == 1 || step == 19)
		return 0;
	else if (a % n == 0)
	{
		printf("%lld\n", a);
		flag = 1;
		return 1;
	}
	else
	{
		if (!dfs(a * 10, step + 1))
		{
			dfs(a * 10 + 1, step + 1);
		}
	}
}

int main()
{
	while (scanf("%d", &n), n)
	{
		flag = 0;
		dfs(1, 0);
	}
}