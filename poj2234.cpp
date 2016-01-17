#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		int a = 0, b;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &b);
			a ^= b;
		}
		if (a == 0)
			printf("No\n");
		else
			printf("Yes\n");
	}
}