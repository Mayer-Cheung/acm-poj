#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1005;
int cost[MAXN][MAXN];
int d[MAXN];
bool used[MAXN];
int n;

void dijkstra(int s)
{
	memset(used, 0, sizeof(used));
	d[1] = 1e9;
	while (true)
	{
		int v = -1;
		for (int u = 1; u <= n; u++)
		{
			if (!used[u] && (v == -1 || d[u] > d[v]))
				v = u;
		}
		if (v == -1)
			break;
		used[v] = true;
		for (int u = 1; u <= n; u++)
			d[u] = max(d[u], min(d[v], cost[v][u]));
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int test = 1; test <= t; test++)
	{
		int m;
		scanf("%d%d", &n, &m);
		memset(cost, 0, sizeof(cost));
		memset(d, 0, sizeof(d));
		for (int i = 0; i < m; i++)
		{
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			cost[a][b] = cost[b][a] = c;
		}
		dijkstra(1);
		printf("Scenario #%d:\n", test);
		printf("%d\n\n", d[n]);
	}
}