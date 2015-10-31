#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;
int n, m;
const int MAXN = 40;
double dist[MAXN];

struct Edge
{
	int src, dst;
	double rate;
}edge[MAXN * MAXN];
map <string, int> mp;

bool bellman_ford(int s)
{
	memset(dist, 0, sizeof(dist));
	dist[s] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < m ;j++)
		{
			int u = edge[j].src;
			int v = edge[j].dst;
			double r = edge[j].rate;
			if (dist[v] < dist[u] * r)
				dist[v] = dist[u] * r;
		}
	}
	if (dist[s] > 1.0)
		return true;
	else
		return false;
}
int main()
{
	int t = 1;
	while (scanf("%d", &n), n)
	{
		mp.clear();
		string s;
		for (int i = 1; i <= n; i++)
		{
			cin >> s;
			mp[s] = i;
		}

		scanf("%d", &m);
		string src, dst;
		double rt;
		for (int i = 0; i < m; i++)
		{
			cin >> src >> rt >> dst;
			edge[i].src = mp[src];
			edge[i].dst = mp[dst];
			edge[i].rate = rt;
		}
		bool flag = false;
		for (int i = 1; i <= n; i++)
		{
			if (bellman_ford(i))
			{
				flag = true;
				break;
			}
		}
		printf("Case %d: ", t++);
		if (flag)
			printf("Yes\n");
		else
			printf("No\n");
	}
}