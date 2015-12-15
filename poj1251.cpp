#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 30;
const int INF = 1e9;
int cost[MAXN][MAXN];
int mincost[MAXN];
bool used[MAXN];
int n;

int prim()
{
	for (int i = 0; i < n; i++)
	{
		mincost[i] = INF;
		used[i] = false;
	}

	mincost[0] = 0;
	int res = 0;

	while (true)
	{
		int v = -1;
		for (int u = 0; u < n; u++)
		{
			if (!used[u] && (v == -1 || mincost[u] < mincost[v]))
				v = u;
		}
		if (v == -1)
			break;
		used[v] = true;

		res += mincost[v];
		for (int u = 0; u < n; u++)
		{
			mincost[u] = min(mincost[u], cost[v][u]);
		}
	}
	return res;
}

int main()
{
	while (cin >> n && n != 0)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cost[i][j] = i == j ? 0 : INF;
		for (int i = 1; i < n; i++)
		{
			char c, d;
			int m, s;
			cin >> c >> m;
			int index = c - 'A';
			cout << "index is " << index << endl;
			for (int j = 0; j < m; j++)
			{
				scanf("%c%d", &d, &s);
				cout << "char index is " << d - 'A' << " " << s << endl;
				cost[index][d - 'A'] = s;
			}
		}

		printf("%d\n", prim());
	}
}