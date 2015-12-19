#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int cnt, n;
		scanf("%d%d", &cnt, &n);
		int ans = 0;
		for (int i = 2; i * (i + 1) / 2 <= n; i++)
		{
			if ((n - i * (i + 1) / 2) % i == 0)
				ans++;
		}
		printf("%d %d\n", cnt, ans);
	}
}