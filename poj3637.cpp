#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MANX = 20000 + 5;
int a[MANX];

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		sort(a + 1, a + 1 + n, cmp);
		int sum = 0;
		for (int i = 3; i <= n; i += 3)
			sum += a[i];
		printf("%d\n", sum);
	}

}