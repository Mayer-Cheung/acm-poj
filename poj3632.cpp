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
		int t_min = 1e9, t_max = -1e9;
		int n;
		scanf("%d", &n);
		while (n--)
		{
			int temp;
			scanf("%d", &temp);
			t_min = min(temp, t_min);
			t_max = max(temp, t_max);
		}
		printf("%d\n", (t_max - t_min) * 2);
	}
}