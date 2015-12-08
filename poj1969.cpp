#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		int sum = 0, index = 1;
		while (sum < n)
		{
			sum += index++;
		}
		index--;
		if (index % 2 == 0)
		{
			printf("TERM %d IS %d/%d\n", n, index + n - sum, sum + 1 - n);
		}
		else
			printf("TERM %d IS %d/%d\n", n, sum + 1 - n, index + n - sum);
	}
}