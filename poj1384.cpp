#include <iostream>

#include <cstdio>

using namespace std;

const int MAXN = 10005;

int f[MAXN], c[505], w[505];

inline int min(int a, int b)
{
	return a < b ? a : b;
}
int main()
{
	int t, E, F, n;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &E, &F);
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d%d", &w[i], &c[i]);

		for (int i = 0; i < MAXN; i++)
			f[i] = 1e9;
		
		f[E] = 0;
		for (int i = 0; i < n; i++)
			for (int v = c[i] + E; v <= F; v++)
				f[v] = min(f[v], f[v - c[i]] + w[i]);

		if (f[F] == 1e9)
			printf("This is impossible.\n");
		else
			printf("The minimum amount of money in the piggy-bank is %d.\n", f[F]);
	}
}