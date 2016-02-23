#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			int temp;
			scanf("%d", &temp);
			sum += temp;
		}
		sum -= n - 1;
		printf("%d\n", sum);
	}
}