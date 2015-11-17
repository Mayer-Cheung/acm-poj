#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 755;
const int MAXM = 500005;

struct Edge
{
	int u, v, dist;
	Edge(){}
	Edge(int u, int v, int d):u(u), v(v), dist(d){}
	bool operator<(const Edge &rhs)const
	{
		return dist < rhs.dist;
	}
};

struct Kruskal
{
	int n, m;
	Edge ed[MAXM];
	int fa[MAXN];
	int findset(int x)
	{
		return fa[x] == -1? x : fa[x] = findset(fa[x]);
	}

	void init(int n)
	{
		this->n = n;
		m = 0;
		memset(fa, -1, sizeof(fa));
	}

	void AddEdge(int u, int v, int dist)
	{
		ed[m++] = Edge(u, v, dist);
	}

	int kruskal()
	{
		int sum = 0;
		int cnt = 0;
		sort(ed, ed + m);

		for (int i = 0; i < m; i++)
		{
			int u = ed[i].u;
			int v = ed[i].v;
			if (findset(u) != findset(v))
			{
				if (ed[i].dist > 0)
					printf("%d %d\n", u, v);l
				sum += ed[i].dist;
				fa[findset(u)] = findset(v);
				if (++cnt >= n - 1)
					break;
			}
		}
		if (cnt < n - 1)
			return -1;
		return sum;
	}
}kk;

struct Point
{
	int x, y;
}p[MAXN];

int get_dist(int i, int j)
{
	return (p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y);
}

int main()
{
	int n, m;
	while (scanf("%d", &n) == 1)
	{
		KK.init(n);
		for (int i = 1; i <= n; i++)
			scanf("%d%d", &p[i].x, &p[i].y);

		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				KK.AddEdge(i, j, get_dist(i, j));

		scanf("%d", &m);
		for (int i = 0; i < m; i++)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			KK.AddEdge(u, v, 0);
		}
		KK.kruskal();
	}
	return 0;
}