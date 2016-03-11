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
		char a[105], b[105];
		scanf("%s%s", a, b);
		bool flag = false;
		int lenA = strlen(a), lenB = strlen(b);
		int i, j;

		for (i = 0, j = 0; i < lenA && !flag; i++)
			if (a[i] == b[j])
			{
				j++;
				if (j == lenB)
				{
					flag = true;
				}
			}

		for (i = 0, j = lenB - 1; i < lenA && !flag; i++)
			if (a[i] == b[j])
			{
				j--;
				if (j == -1)
				{
					flag = true;
				}
			}

		if (flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
}