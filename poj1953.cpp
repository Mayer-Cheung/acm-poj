#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int a[50];

void init()
{	
	a[0] = 1;
	a[1] = 2;
	for (int i = 2; i <= 45; i++)
		a[i] = a[i - 1] + a[i - 2];
}

int main()
{
	int n, t;
	scanf("%d", &n);
	init();
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &t);
		printf("Scenario #%d:\n", i);
		printf("%d\n\n", a[t]);
	}
}