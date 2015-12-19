#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		int i = 1;
		long long pro = 1;
		while (true)
		{
			if (pro % n == 0)
			{
				break;
			}
			i++;
			pro = 10 * pro + 1;
			pro %= n;
		}

		printf("%d\n", i);
	}
}