#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int n;
	while (scanf("%d", &n) && n)
	{
		if (n & 1)
			printf("%d\n", n - 1);
		else
			printf("No Solution!\n");
	}
}