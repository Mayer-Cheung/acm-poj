#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

char a[11];
int main()
{
	scanf("%s", a);
	int sum = 0, pos = 0, poswei = 0, weight = 10;
	for (int i = 0; i < 10; i++)
	{
		if (a[i] == '?')
		{
			pos = i;
			poswei = weight;
			weight--;
		}
		else if (a[i] == 'X')
		{
			sum += weight * 10;
			weight--;
		}
		else
		{
			sum += (a[i] - '0') * weight;
			weight--;
		}
	}
	int x = pos == 9 ? 1 : 0;
	bool flag = false;
	for (int i = 0; i < 10 + x; i++)
	{
		if ((sum + poswei * i) % 11 == 0)
		{
			if (i == 10)
				printf("X\n");
			else
				printf("%d\n", i);
			flag = true;
			break;
		}
	}
	if (!flag)
		printf("-1\n");
}