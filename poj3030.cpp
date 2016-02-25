#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	while (n--)
	{
		int no, yes, cost;
		scanf("%d%d%d", &no, &yes, &cost);
		if (no + cost < yes)
			printf("advertise\n");
		else if (no + cost == yes)
			printf("does not matter\n");
		else
			printf("do not advertise\n");
	}
}