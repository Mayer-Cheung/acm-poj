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