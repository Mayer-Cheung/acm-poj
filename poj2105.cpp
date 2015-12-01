#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
char a[32];
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%s", a);
		for (int i = 0; i < 4; i++)
		{
			int ans = 0, weight = 1;
			for (int j = (i + 1) * 8 - 1; j >= i * 8; j--)
			{
				ans += weight * (a[j] - '0');
				weight *= 2;
			}
			printf("%d", ans);
			if (i != 3)
				printf(".");
		}
		printf("\n");
	}
}