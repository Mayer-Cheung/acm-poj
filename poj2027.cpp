#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int t, x, y;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &x, &y);
		if (x >= y)
			printf("MMM BRAINS\n");
		else
			printf("NO BRAINS\n");
	}
}