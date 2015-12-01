#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 1005;

vector<int> a[MAXN];
int vis[MAXN], ans[MAXN], cow[MAXN];
int k, n, m;

void DFS(int index)
{
	for (int i = 0; i < a[index].size(); i++)
	{
		if (!vis[a[index][i]])
		{
			ans[a[index][i]]++;
			vis[a[index][i]] = 1;
			DFS(a[index][i]);
		}
	}
}

int main()
{
	while (scanf("%d%d%d", &k, &n, &m) != EOF)
	{
		memset(ans, 0, sizeof(ans));

		for (int i = 1; i <= k; i++)
			scanf("%d", &cow[i]);

		for (int i = 0; i < m; i++)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			a[u].push_back(v);
		}

		for (int i = 1; i <= k; i++)
		{
			memset(vis, 0, sizeof(vis));
			vis[cow[i]] = 1;
			ans[cow[i]]++;
			DFS(cow[i]);
		}

		int count = 0;
		for (int i = 1; i <= n; i++)
			if (ans[i] == k)
				count++;

		printf("%d\n", count);
	}
}