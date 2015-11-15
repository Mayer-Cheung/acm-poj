#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 305;
const int INF = 1e8;

int a[MAXN][MAXN];

int main()
{
	int n, m, t;
	int from, to, hei;
	scanf("%d%d%d", &n, &m, &t);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			a[i][j] = i == j? 0 : INF;
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &from, &to, &hei);
		a[from][to] = hei;
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (a[i][k] < INF && a[k][j] < INF)
					a[i][j] = min(max(a[i][k], a[k][j]), a[i][j]);

	for (int i = 0; i < t; i++)
	{
		scanf("%d%d", &from, &to);
		printf("%d\n", a[from][to] == INF? -1 : a[from][to]);
	}
}