#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXV = 505;
const int INF = 1e2;

struct edge
{
	int to;
	int cap;
	int rev;
};

vector<edge> G[MAXV];
bool used[MAXV];

void add_edge(int from, int to, int cap)
{
	G[from].push_back((edge){to, cap, G[to].size()});
	G[to].push_back((edge){from, 0, G[from].size() - 1});
}

int dfs(int s, int t, int f)
{
	if (s == t)
		return f;
	used[s] = true;
	for (int i = 0; i < G[s].size(); i++)
	{
		edge &e = G[s][i];
		if (!used[e.to] && e.cap > 0)
		{
			int d = dfs(e.to, t, min(f, e.cap));
			if (d > 0)
			{
				e.cap -= d;
				G[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
    return 0;
}

int max_flow(int s, int t)
{
	int flow = 0;
	for (;;)
	{
		memset(used, 0, sizeof(used));
		int f = dfs(s, t, INF);
		if (f == 0)
			return flow;
		flow += f;
	}
}


int main()
{
	int n, m;
	
	while (scanf("%d%d", &n, &m) != EOF)
	{
		memset(G, 0, sizeof(G));
		for (int i = 1; i <= n; i++)
			add_edge(0, i, 1);
		for (int i = n + 1; i <= n + m; i++)
			add_edge(i, n + m + 1, 1);
		for (int i = 1; i <= n; i++)
		{
			int t;
			scanf("%d", &t);
			for (int j = 0; j < t; j++)
			{
				int to;
				scanf("%d", &to);
				add_edge(i, to + n, 1);
			}
		}
		printf("%d\n", max_flow(0, n + m + 1));
	}
}