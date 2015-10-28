#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
const int MAX_V = 100005;
const int INF = 1000000;
struct edge
{
	int to, cost;
	edge(int a, int b)
	{
		to = a;
		cost = b;
	}
};
typedef pair<int, int> P;
int V, E;
int dist[MAX_V];
int dist2[MAX_V];
vector<edge> G[MAX_V];

void solve()
{
	priority_queue<P, vector<P>, greater<P> > que;
	memset(dist, INF, sizeof(dist));
	memset(dist2, INF, sizeof(dist2));
	dist[0] = 0;
	que.push(P(0, 1));

	while (!que.empty())
	{
		P p = que.top();
		que.pop();
		int v = p.second, d = p.first;
		if (dist2[v] < d)
			continue;
		for (int i = 0; i < G[v].size(); i++)
		{
			edge &e = G[v][i];
			int d2 = d + e.cost;
			if (dist[e.to] > d2)
			{
				swap(dist[e.to], d2);
				que.push(P(dist[e.to], e.to));
			}
			if (dist2[e.to] > d2 && dist[e.to] < d2)
			{
				dist2[e.to] = d2;
				que.push(P(dist2[e.to], e.to));
			}
		}
	}
	printf("%d\n", dist2[V]);
}
int main()
{
	scanf("%d%d", &V, &E);
	int from, cost, to;
	for (int i = 0; i < E; i++)
	{
		scanf("%d%d%d", &from, &to, &cost);
		G[from].push_back(edge(to, cost));
		G[to].push_back(edge(from, cost));
	}
	solve();
}