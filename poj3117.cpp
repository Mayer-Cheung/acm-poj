#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int n, m;
	while (scanf("%d%d", &n, &m), n != 0 || m != 0)
	{
		char str[15];
		int sum = 0, s;
		for (int i = 0; i < n; i++)
		{
			scanf("%s%d", str, &s);
			sum += s;
		}
		printf("%d\n", 3 * m - sum);		
	}
}