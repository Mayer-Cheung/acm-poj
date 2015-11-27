#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 12890;

int f[MAXN], w[3405], d[3405];

inline int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &w[i], &d[i]);

	for (int i = 0; i < MAXN; i++)
		f[i] = 0;

	for (int i = 0; i < n; i++)
		for (int v = m; v >= w[i]; v--)
			f[v] = max(f[v], f[v - w[i]] + d[i]);

	printf("%d\n", f[m]);
}