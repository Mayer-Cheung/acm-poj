#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

const int ALL = (1 << 26) - 1; 
const int MAXN = 205;
int mp[MAXN][MAXN];

int main()
{
	int n;
	while (scanf("%d", &n) == 1 && n)
	{
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				mp[i][j] = i == j? ALL : 0;

		int u, v;
		while (scanf("%d%d", &u, &v) == 2 && u)
		{
			int val = 0;
			char str[200];
			scanf("%s", str);
			int len = strlen(str);
			for (int i = 0; i < len; i++)
				val |= 1 << (str[i] - 'a');
			mp[u][v] = val;
		}

		for (int k = 1; k <= n; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					mp[i][j] |= mp[i][k] & mp[k][j];

		while (scanf("%d%d", &u, &v) == 2 && u)
		{
			if (mp[u][v] == 0)
				printf("-\n");
			else
			{
				for (int i = 0; i < 26; i++)
					if (mp[u][v] & (1 << i))
						printf("%c", 'a' + i);
					printf("\n");
			}
		}
		printf("\n");
	}
}