#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 35;
int main()
{
	char s[100];
	int total[MAXN], word[MAXN][100];
	memset(total, 0, sizeof(total));
	for (int i = 0; i < 4; i++)
	{
		gets(s);
		int len = strlen(s);
		for (int j = 0; j < len; j++)
			total[s[j] - 'A']++;
	}

	int max_t = total[0];
	for (int i = 0; i <= 25; i++)
		max_t = max(max_t, total[i]);

	memset(word, 0, sizeof(word));

	for (int i = 0; i <= 25; i++)
		for (int j = 1; j <= total[i]; j++)
			word[i][j] = 1;

	for (int i = max_t; i > 0; i--)
	{
		for (int j = 0; j <= 25; j++)
		{
			if (!word[j][i] && j == 0)
				printf(" ");
			else if (word[j][i] && j == 0)
				printf("*");
			else if (!word[j][i])
				printf("  ");
			else if (word[j][i])
				printf(" *");
		}
		printf("\n");
	}
	for (int i = 0; i <= 25; i++)
	{
		if (i == 0)
			printf("%c", i + 'A');
		else
			printf(" %c", i + 'A');
	}
	printf("\n");
}