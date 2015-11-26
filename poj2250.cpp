#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 128;
struct Word
{
	char s[32];
}a[MAXN], b[MAXN];

int dp[MAXN][MAXN], match[MAXN][MAXN];

void print(int x, int y)
{
	if (x == 0 || y == 0)
		return;
	if (match[x][y] == 0)
	{
		print(x - 1, y - 1);
		printf("%s ", a[x].s);
	}
	else if (match[x][y] == 1)
		print(x, y - 1);
	else if (match[x][y] == 2)
		print(x - 1, y);
}

int main()
{
	while (true)
	{
		int t = 1, p = 1, q = 1;
		while (true)
		{
			t = scanf("%s", a[p++].s);
			if (t == -1)
				break;
			if (a[p - 1].s[0] == '#')
			{
				--p;
				break;
			}
		}

		if (t == -1)
			break;

		while (true)
		{
			scanf("%s", b[q++].s);
			if (b[q - 1].s[0] == '#')
			{
				--q;
				break;
			}
		}
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i < p; i++)
			for (int j = 1; j < q; j++)
			{
				if (!strcmp(a[i].s, b[j].s))
				{
					dp[i][j] = dp[i - 1][j - 1] + 1;
					match[i][j] = 0;
				}
				else
				{
					if (dp[i][j - 1] > dp[i - 1][j])
					{
						dp[i][j] = dp[i][j - 1];
						match[i][j] = 1;
					}
					else
					{
						dp[i][j] = dp[i - 1][j];
						match[i][j] = 2;
					}
				}
			}
		print(p - 1, q - 1);
		printf("\n");
	}
}