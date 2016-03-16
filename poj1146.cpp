#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 50 + 5;
char str[MAXN];

int check()
{
	int l = strlen(str);
	int i = l - 1;
	while (i > 0 && str[i] <= str[i - 1])
		i--;
	if (i == 0)
		return 0;
	int j = i;
	for (int k = l - 1; k > i; k--)
		if (str[k] > str[i - 1])
		{
			j = k;
			break;
		}
	swap(str[i - 1], str[j]);
	sort(str + i, str + l);
	return 1;


}

int main()
{
	while (true)
	{
		scanf("%s", str);
		if (str[0] == '#')
			break;
		if (check() == 0)
			printf("No Successor\n");
		else
			printf("%s\n", str);
	}
}