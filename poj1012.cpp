#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	int joseph[14];
	int k;
	memset(joseph, 0, sizeof(joseph));
	while (scanf("%d", &k) && k)
	{
		if (joseph[k])
		{
			printf("%d\n", joseph[k]);
			continue;
		}
		int n = 2 * k;
		int ans[30] = {};

		int m = 1;
		for (int i = 1; i <= k; i++)
		{
			ans[i] = (ans[i - 1] + m - 1) % (n - i + 1);
			if (ans[i] < k)
			{
				m++;
				i = 0;
			}
		}
		joseph[k] = m;
		printf("%d\n", m);
	}
}