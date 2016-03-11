#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		char str[1005];
		scanf("%s", str);
		int prev_cnt = 1;
		char prev_char = str[0];
		for (int i = 1; i < strlen(str); i++)
		{
			if (str[i] == prev_char)
				prev_cnt++;
			else
			{
				printf("%d%c", prev_cnt ,prev_char);
				prev_char = str[i];
				prev_cnt = 1;
			}
		}
		printf("%d%c", prev_cnt ,prev_char);
		printf("\n");
	}
}