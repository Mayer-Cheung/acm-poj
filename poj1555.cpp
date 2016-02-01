#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int MAXN = 9;
int a[MAXN];


int main()
{
	while (scanf("%d", &a[0]) != EOF)
	{
		for (int i = 1; i < MAXN; i++)
			scanf("%d", &a[i]);
		int allsum = 0;
		for (int i = 0; i < MAXN; i++)
			allsum += a[i];
		if (allsum == 0)
		{
			printf("0\n");
			continue;
		}
		bool first = true;
		for (int i = 0; i < MAXN - 2; i++)
		{
			if (a[i] == 0)
				continue;
			if (!first)
			{
				if (a[i] > 0)
				{
					if (a[i] == 1)
						printf(" + x^%d", 8 - i);
					else
						printf(" + %dx^%d", a[i], 8 - i);
				}
				else if (a[i] < 0)
				{
					if (a[i] == -1)
						printf(" - x^%d", 8 - i);
					else
						printf(" - %dx^%d", -a[i], 8 - i);
				}
			}
			else
			{
				if (a[i] > 0)
				{
					if (a[i] == 1)
						printf("x^%d", 8 - i);
					else
						printf("%dx^%d", a[i], 8 - i);
				}
				else if (a[i] < 0)
				{
					if (a[i] == -1)
						printf("-x^%d", 8 - i);
					else
						printf("%dx^%d", a[i], 8 - i);
				}
				first = false;
			}
		}
			if (first && a[7] != 0)
			{
				if (a[7] > 0)
				{
					if (a[7] == 1)
						printf("x");
					else
						printf("%dx", a[7]);
				}
				else if (a[7] < 0)
				{
					if (a[7] == -1)
						printf("-x");
					else
						printf("%dx", -a[7]);
				}
			}
			else if (!first && a[7] != 0)
			{
				if (a[7] > 0)
				{
					if (a[7] == 1)
						printf(" + x");
					else
						printf(" + %dx", a[7]);
				}
				else if (a[7] < 0)
				{
					if (a[7] == -1)
						printf(" - x");
					else
						printf(" - %dx", -a[7]);
				}
				first = false;
			}

			if (first && a[8] != 0)
			{
				printf("%d", a[8]);
			}
			else if (!first && a[8] != 0)
			{
				if (a[8] > 0)
					printf(" + %d", a[8]);
				else
					printf(" - %d", -a[8]);
			}		
		printf("\n");
	}
}