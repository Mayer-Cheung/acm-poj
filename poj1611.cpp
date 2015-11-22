#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 30005;

int fa[MAXN];
int num[MAXN];

int findset(int x)
{
	return fa[x] == -1 ? x : fa[x] = findset(fa[x]);
}

void bind(int u, int v)
{
	int fu = findset(u);
	int fv = findset(v);
	if (fu != fv)
	{
		fa[fv] = fu;
		num[fu] += num[fv];
	}
}
int main()
{
	int n, m, t, u, v;
	while (scanf("%d%d", &n, &m), n + m)
	{
		for (int i = 0; i <= n; i++)
		{
			fa[i] = -1;
			num[i] = 1;
		}
		for (int i = 0; i < m; i++)
		{
			scanf("%d%d", &t, &u);
			for (int i = 1; i < t; i++)
			{
				scanf("%d", &v);
				bind(u, v);
			}
		}
		printf("%d\n", num[findset(0)]);
	}
}