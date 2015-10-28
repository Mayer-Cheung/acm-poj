#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[500005];
int main()
{
	int n;
	while (scanf("%d", &n), n)
	{
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		int cnt = 0;
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				if (a[j] < a[j - 1])
				{
					swap(a[j], a[j - 1]);
					cnt++;
				}
		printf("%d\n", cnt);
	}
}