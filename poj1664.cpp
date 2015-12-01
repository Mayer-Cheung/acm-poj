#include <iostream>
#include <cstdio>

using namespace std;

int count(int m, int n)  //  m apples, n dishes
{
	if (m == 0 || n == 1)
		return 1;
	if (n > m)
		return count(m, m);
	return count(m, n - 1) + count(m - n, n);
}

int main()
{
	int cnt;
	int apple, dish;
	while (scanf("%d", &cnt) != EOF)
	{
		while (cnt--)
		{
			scanf("%d%d", &apple, &dish);
			printf("%d\n", count(apple, dish));
		}
	}
}