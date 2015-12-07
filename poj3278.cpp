#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int vis[100005];
struct Node
{
	int pos, steps;
	Node(int a, int b)
	{
		pos = a;
		steps = b;
	}
};

queue<Node> q;
void bfs(int s, int e)
{
	Node a(s, 0);
	q.push(a);
	vis[a] = 1;
	while (!q.empty())
	{
		Node b = q.front();
		q.pop();
		if (b.pos == e)
		{
			printf("%d\n", b.steps);
			break;
		}
		if (b.pos + 1 <= 100000 && vis[b.pos + 1] == 0)
		{
			q.push(Node(b.pos + 1, b.steps + 1));
			vis[b.pos + 1] = 1;
		}
		if (b.pos - 1 >= 0 && vis[b.pos - 1] == 0)
		{
			q.push(Node(b.pos - 1, b.steps + 1));
			vis[b.pos - 1] = 1;
		}
		if (b.pos * 2 <= 100000 && vis[b.pos * 2] == 0)
		{
			vis[b.pos * 2] = 1;
			q.push(Node(b.pos * 2, b.steps + 1));
		}
	}
}

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	memset(vis, 0, sizeof(vis));
	if (a > b)
		printf("%d\n", a - b);
	else
		bfs(a, b);
}