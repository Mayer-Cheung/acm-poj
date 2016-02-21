#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if ((a - b) >= 0 && (a - b) % 2 == 0)
		{
			printf("%d %d\n", (a + b) / 2, (a - b) / 2);
		}
		else
			printf("impossible\n");
	}
}