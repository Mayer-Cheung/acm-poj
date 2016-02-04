#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXN = 65;
char table[15][MAXN];

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%s", table[i]);

		bool flag = true;
		char ans[MAXN];
		int len = 0;
		for (int i = 0; i < strlen(table[0]); i++)
			for (int j = i + 2; j < strlen(table[0]); j++)
			{
				char s[MAXN];
				strncpy(s, table[0] + i, j - i + 1);
				s[j - i + 1] = '\0';
				flag = true;
				for (int k = 1; flag && k < n; k++)
				{
					if (strstr(table[k], s) == NULL)
						flag = false;
				}
				if (flag && ((j - i + 1) > len || (j - i + 1) == len && strcmp(ans, s) > 0))
				{
					len = j - i + 1;
					strcpy(ans, s);
				}
			}

		if (len < 3)
			printf("%s\n", "no significant commonalities");
		else
			printf("%s\n", ans);
	}
}