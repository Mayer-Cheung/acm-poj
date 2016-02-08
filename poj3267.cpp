#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int W, L, i, j;

int main()
{
	scanf("%d", &W, &L);
	char word[305];
	int ans = L;
	scanf("%s", word);
	for (int t = 0; t < W; t++)
	{
		char dict[30];
		scanf("%s", dict);
		for (i = 0, j = 0; i < strlen(word); i++)
		{
			if (word[i] == dict[j])
				j++;
		}
		if (j == strlen(dict))
			ans -= j;
	}
	printf("%d\n", ans);
	system("pause");
}