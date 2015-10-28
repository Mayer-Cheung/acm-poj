#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		int sum = 0, temp = 1;
		for (int n = 1; n <= 20; n++)
		while (true)
		{
			sum += temp++;
			if (sum > n)
			{
				n = sum - n;
				break;
			}
		}
		printf("%d\n", n);
	}
}