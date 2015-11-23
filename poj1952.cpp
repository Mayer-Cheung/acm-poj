#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 5005;

int price[MAXN], len[MAXN], num[MAXN];

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &price[i]);
			len[i] = 1;
			num[i] = 1;
		}

		for (int i = 1; i < n; i++)
			for (int j = i - 1; j >= 0; j--)
			{
				if (price[i] < price[j])
				{
					if (len[j] + 1 > len[i])
					{
						len[i] = len[j] + 1;
						num[i] = num[j];
					}
					else if (len[i] == len[j] + 1)
						num[i] += num[j];
				}
				else if (price[i] == price[j])
				{
					if (len[i] == 1)
						num[i] = 0;
					break;
				}
			}
		int anslen = 0, ansnum = 0;
		for (int i = 0; i < n; i++)
			anslen = max(anslen, len[i]);
		for (int i = 0; i < n; i++)
			if (len[i] == anslen)
				ansnum += num[i];

		printf("%d %d\n", anslen, ansnum);
	}
}