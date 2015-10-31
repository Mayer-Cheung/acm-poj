#include <iostream>
#include <cstdio>
using namespace std;
char str[25][35];
int main()
{
	int test = 1;
	int n;
	while (scanf("%d", &n), n)
	{
		for (int i = 0; i < n; i++)
			scanf("%s", &str[i]);
		printf("SET %d\n", test++);
		for (int i = 0; i < n; i += 2)
			printf("%s\n", str[i]);
		if (n & 1)
			n -= 2;
		else
			n--;
		for (; n > 0; n -= 2)
			printf("%s\n", str[n]);
	}
}