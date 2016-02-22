#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

const int MAXN = 205;
int cost[MAXN][MAXN];

struct Point {
	int x, y;
}p[MAXN];
double d[MAXN];
bool used[MAXN];
int n;

double dist(Point a, Point b) {
	return sqrt((double)(a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void dijkstra(int s) {
	fill(d, d + n + 1, 1e9);
	fill(used, used + n + 1, 0);
	d[s] = 0;
	while (true) {
		int v = -1;
		for (int u = 1; u <= n; u++) {
			if (!used[u] && (v == -1 || d[u] < d[v]))
				v = u;
		}
		if (v == -1)
			break;
		used[v] = true;
		for (int u = 1; u <= n; u++)
		{

			d[u] = min(d[u], max(d[v], dist(p[u], p[v])));
		}
	}
}

int main() {
	int t = 1;
	while (scanf("%d", &n), n) {
		scanf("%d%d", &p[1].x, &p[1].y);
		scanf("%d%d", &p[n].x, &p[n].y);
		for (int i = 2; i < n; i++)
			scanf("%d%d", &p[i].x, &p[i].y);
		dijkstra(1);
		printf("Scenario #%d\n", t++);
		printf("Frog Distance = %.3f\n\n", d[n]);
	}
}