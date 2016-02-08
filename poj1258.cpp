//  prime
#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 105;
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
			mincost[u] = min(mincost[u], cost[v][u]);
	}
	return res;
}

int main()
{
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &cost[i][j]);

		printf("%d\n", prim());
	}
}

//  kruscal
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 105;

int par[MAXN], rnk[MAXN], n;

struct Edge
{
	int u, v, cost;
	Edge(int a, int b, int c)
	{
		u = a, v = b, cost = c;
	}
};

vector<Edge> vec;

bool cmp(const Edge& e1, const Edge& e2)
{
	return e1.cost < e2.cost;
}

void init_union_find(int n)
{
	for (int i = 0; i < n; i++)
	{
		par[i] = i;
		rnk[i] = 0;
	}
}

int find(int x)
{
	if (par[x] == x)
		return x;
	else
		return par[x] = find(par[x]);
}

void unite(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)
		return;

	if (rnk[x] < rnk[y])
		par[x] = y;
	else
	{
		par[y] = x;
		if (rnk[x] == rnk[y])
			rnk[x]++;
	}
}

bool same(int x, int y)
{
	return find(x) == find(y);
}

int kruscal()
{
	sort(vec.begin(), vec.end(), cmp);
	init_union_find(n);
	int res = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		Edge e = vec[i];
		if (!same(e.u, e.v))
		{
			unite(e.u, e.v);
			res += e.cost;
		}
	}
	return res;
}

int main()
{
	while (scanf("%d", &n) != EOF)
	{
		vec.clear();
		int temp;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				scanf("%d", &temp);
				if (i != j)
				{
					Edge a(i, j, temp);
					Edge b(j, i, temp);
					vec.push_back(a);
					vec.push_back(b);
				}
			}
		}
		printf("%d\n", kruscal());
	}
}