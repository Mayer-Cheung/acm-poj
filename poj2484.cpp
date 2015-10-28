#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	while (scanf("%d", &n), n)
	{
		if (n > 2)
			printf("Bob\n");
		else
			printf("Alice\n");
	}
}