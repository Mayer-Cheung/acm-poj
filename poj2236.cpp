#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 1005;

int fa[MAXN];

int findset(int x)
{
	return fa[x] == -1? x : fa[x] = findset(fa[x]);
}

void bind(int u, int v)
{
	int fu = findset(u);
	int fv = findset(v);
	if (fu != fv)
	{
		fa[fu] = fv;
	}
}

struct Point
{
	double x, y;
}p[MAXN];

double dist(Point p1, Point p2)
{
	return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int main()
{
	int n;
	double d;
	bool vis[MAXN];
	vector<int> vc[MAXN];
	scanf("%d%lf", &n, &d);
	memset(fa, -1, sizeof(fa));
	memset(vis, 0, sizeof(vis));

	for (int i = 1; i <= n; i++)
		scanf("%lf%lf", &p[i].x, &p[i].y);

	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
		{
			if (dist(p[i], p[j]) <= d * d)
				vc[i].push_back(j), vc[j].push_back(i);
		}

	char com[10];

	while (scanf("%s", com) == 1)
	{
		if (com[0] == 'O')
		{
			int u;
			scanf("%d", &u);
			vis[u] = true;
			for (int i = 0; i < vc[u].size(); i++)
			{
				int v = vc[u][i];
				if (vis[v])
					bind(u, v);
			}
		}
		else if (com[0] == 'S')
		{
			int u, v;
			scanf("%d%d", &u, &v);
			if (vis[u] && vis[v] && findset(u) == findset(v))
				printf("SUCCESS\n");
			else
				printf("FAIL\n");
		}
	}
}