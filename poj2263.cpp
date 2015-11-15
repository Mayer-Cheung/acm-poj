#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <string>

using namespace std;

const int MAXN = 205;
const int INF = 1e9;

int a[MAXN][MAXN], cnt;

map<string, int> mp;
int ID(string s)
{
	if (mp.find(s) == mp.end())
		mp[s] = ++cnt;
	return mp[s];
}
int main()
{
	int n, r, test = 1;
	while (scanf("%d%d", &n, &r), n + r)
	{
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				a[i][j] = i == j? INF : 0;
		mp.clear();
		cnt = 0;
		int id1, id2, limit;
		string from, to;
		for (int i = 0; i < r; i++)
		{
			cin >> from >> to >> limit;
			id1 = ID(from);
			id2 = ID(to);
			a[id1][id2] = limit;
			a[id2][id1] = limit;
		}

		for (int k = 1; k <= n; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					if (a[i][k] > 0 && a[k][j] > 0)
						a[i][j] = max(a[i][j], min(a[i][k], a[k][j]));

		string s1, s2;
		cin >> s1 >> s2;
		int u = ID(s1), v = ID(s2);
		printf("Scenario #%d\n", test++);
		printf("%d tons\n\n", a[u][v]);

	}
}