#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
	int t, k, ans, cnt, res, temp;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &k);
		res = cnt = 0;
		ans = k % 2;
		for (int i = 0; i < k; i++)
		{
			scanf("%d", &temp);
			if (ans)
				continue;
			if (temp == 0)
			{
				if (i % 2)
					cnt++;
				else
					res++;
			}
		}
		if (ans || abs(cnt - res) <= 1)
			printf("YES\n");
		else
			printf("NO\n");
	}
}