#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
const int MAXN = 20000 + 10;
const int MAXM = 200000 + 10;
const int INF = 1e9;
int a, b, w;

struct Edge
{
	int to, cap, rev;
};

vector<Edge> G[MAXN];
int level[MAXN];
int iter[MAXN];

void add_edge(int from, int to, int cap)
{
	G[from].push_back((Edge){to, cap, G[to].size()});
	G[to].push_back((Edge){from, 0, G[from].size() - 1});
}

void bfs(int s)
{
	memset(level, -1, sizeof(level));
	queue<int> que;
	level[s] = 0;
	que.push(s);
	while (!que.empty())
	{
		int v = que.front();
		que.pop();
		for (int i = 0; i < G[v].size(); i++)
		{
			Edge &e = G[v][i];
			if (e.cap > 0 && level[e.to] < 0)
			{
				level[e.to] = level[v] + 1;
				que.push(e.to);
			}
		}
	}
}

int dfs(int v, int t, int f)
{
	if (v == t)
		return f;
	for (int &i = iter[v]; i < G[v].size(); i++)
	{
		Edge &e = G[v][i];
		if (e.cap > 0 && level[v] < level[e.to])
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
		bfs(s);
		if (level[t] < 0)
			return flow;
		memset(iter, 0, sizeof(iter));
		int f;
		while ((f = dfs(s, t, INF)) > 0)
		{
			flow += f;
		}
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &a, &b);
		add_edge(0, i, a);
		add_edge(i, n + 1, b);
	}
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &a, &b, &w);
		add_edge(a, b, w);
		add_edge(b, a, w);
	}
	printf("%d\n", max_flow(0, n + 1));
}