#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int MAXN = 2005;

int fa[MAXN];
int rank[MAXN];
bool flag;

void init(int n)
{
	for (int i = 0; i < n; i++)
	{
		fa[i] = i;
		rank[i] = 0;
	}
}

int find(int x)
{
	if (fa[x] == x)
		return x;
	else
	{
		int t = fa[x];
		fa[x] = find(fa[x]);
		rank[x] = (rank[x] + rank[t]) % 2;
		return fa[x];
	}
}

void unite(int x, int y)
{
	int fx = find(x);
	int fy = find(y);

	fa[fx] = fy;
	rank[fx] = (rank[x] + rank[y] + 1) % 2;

}

int main()
{
	int t, n, m;
	scanf("%d", &t);
	for (int kase = 1; kase <= t; kase++)
	{
		flag = true;
		scanf("%d%d", &n, &m);
		init(n);
		for (int i = 0; i < m; i++)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			if (find(u) == find(v))
			{
				if (rank[u] == rank[v])
				{
					flag = false;
				}
			}
			else
				unite(u, v);
		}

		printf("Scenario #%d:\n", kase);
		if (flag)
			printf("No suspicious bugs found!\n\n");
		else
			printf("Suspicious bugs found!\n\n");
	}
}