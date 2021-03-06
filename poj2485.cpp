//  prime
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 505;
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
		res = max(res, mincost[v]);
		for (int u = 0; u < n; u++)
		{
			mincost[u] = min(mincost[u], cost[v][u]);
		}
	}
	return res;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &cost[i][j]);

		printf("%d\n", prim());
	}
}

//  kruscal
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 505;
int par[MAXN], rank[MAXN], n;

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

void init_union(int n)
{
	for (int i = 0; i < n; i++)
		par[i] = i, rank[i] = 0;
}

int find(int n)
{
	if (par[n] == n)
		return n;
	else
		return par[n] = find(par[n]);
}

bool same(int a, int b)
{
	return find(a) == find(b);
}

void unite(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)
		return;
	if (rank[x] < rank[y])
	{
		par[x] = y;
	}
	else
	{
		par[y] = x;
		if (rank[x] == rank[y])
			rank[x]++;
	}
}

int kruscal()
{
	sort(vec.begin(), vec.end(), cmp);
	init_union(n);
	int result = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		Edge e = vec[i];
		if (!same(e.u, e.v))
		{
			unite(e.u, e.v);
			if (e.cost > result)
				result = e.cost;
		}
	}
	return result;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		vec.clear();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int temp;
				scanf("%d", &temp);
				if (i > j)
				{
					Edge a(i, j, temp);
					vec.push_back(a);
				}
			}
		}
		printf("%d\n", kruscal());
	}
}