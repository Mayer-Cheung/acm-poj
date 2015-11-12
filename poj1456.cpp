#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 50005;

int fa[MAXN];

int findset(int x)
{
	return fa[x] == -1? x : fa[x] = findset(fa[x]);
}

int bind(int u, int v)
{
	int fu = findset(u);
	int fv = findset(v);
	if (fu != fv)
	{
		fa[fu] = fv;
		return 1;
	}
	return 0;
}

int main()
{
	int n, m;
	int t = 0;
	while (scanf("%d%d", &n, &m) == 2 && n)
	{
		memset(fa, -1, sizeof(fa));
		int cnt = n;

		while (m--)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			cnt -= bind(u, v);
		}

		printf("Case %d: %d\n", ++t, cnt);
	}
}

//  with set union
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 10005;

struct Node
{
	int p, t;
	bool operator < (const Node& b) const
	{
		return p > b.p;
	}
}node[MAXN];

int fa[MAXN];
int findset(int x)
{
	return fa[x] == -1? x : fa[x] = findset(fa[x]);
}

int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		for (int i = 1; i <= n; i++)
			scanf("%d%d", &node[i].p, &node[i].t);

		sort(node + 1, node + 1 + n);

		memset(fa, -1, sizeof(fa));
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			int time = findset(node[i].t);
			if (time > 0)
			{
				cnt += node[i].p;
				fa[time] = time - 1;
			}
		}

		printf("%d\n", cnt);
	}
}