#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

const int MAXN = 10005;
bool prime[MAXN], used[MAXN];
int a, b;

struct Node
{
	int val, step;
	Node(int a, int b)
	{
		val = a;
		step = b;
	}
};
void init()
{
	memset(prime, 1, sizeof(prime));
	prime[0] = prime[1] = false;
	for (int i = 2; i <= MAXN; i++)
		if (prime[i])
			for (int j = 2; j * i <= MAXN; j++)
				prime[i * j] = false;
}

int bfs()
{
	memset(used, 0, sizeof(used));
	int ans = 0;
	queue<Node> que;
	if (prime[b] == false)
		return -1;
	used[a] = true;
	que.push((Node){a, 0});
	while (!que.empty())
	{
		Node temp = que.front();
		used[temp.val] = true;
		que.pop();
		if (temp.val == b)
			return temp.step;

		for (int i = temp.val % 10, j = 1; i + j <= 9; j++)
		{
			int haha = temp.val + j;
			if (!used[haha] && prime[haha])
			{
				que.push((Node){haha, temp.step + 1});
				used[haha] = true;
			}
		}
		for (int i = temp.val % 10, j = 1; i - j >= 0; j++)
		{
			int haha = temp.val - j;
			if (!used[haha] && prime[haha])
			{
				que.push((Node){haha, temp.step + 1});
				used[haha] = true;
			}
		}

		for (int i = (temp.val / 10) % 10, j = 1; i + j <= 9; j++)
		{
			int haha = temp.val + 10 * j;
			if (!used[haha] && prime[haha])
			{
				que.push((Node){haha, temp.step + 1});
				used[haha] = true;
			}
		}
		for (int i = (temp.val / 10) % 10, j = 1; i - j >= 0; j++)
		{
			int haha = temp.val - 10 * j;
			if (!used[haha] && prime[haha])
			{
				que.push((Node){haha, temp.step + 1});
				used[haha] = true;
			}
		}

		for (int i = (temp.val / 100) % 10, j = 1; i + j <= 9; j++)
		{
			int haha = temp.val + 100 * j;
			if (!used[haha] && prime[haha])
			{
				que.push((Node){haha, temp.step + 1});
				used[haha] = true;
			}
		}
		for (int i = (temp.val / 100) % 10, j = 1; i - j >= 0; j++)
		{
			int haha = temp.val - 100 * j;
			if (!used[haha] && prime[haha])
			{
				que.push((Node){haha, temp.step + 1});
				used[haha] = true;
			}
		}

		for (int i = (temp.val / 1000) % 10, j = 1; i + j <= 9; j++)
		{
			int haha = temp.val + 1000 * j;
			if (!used[haha] && prime[haha])
			{
				que.push((Node){haha, temp.step + 1});
				used[haha] = true;
			}
		}
		for (int i = (temp.val / 1000) % 10, j = 1; i - j > 0; j++)
		{
			int haha = temp.val - 1000 * j;
			if (!used[haha] && prime[haha])
			{
				que.push((Node){haha, temp.step + 1});
				used[haha] = true;
			}
		}
			
	}
	return -1;
}

int main()
{
	int t;
	init();
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &a, &b);
		int ans = bfs();
		if (ans == -1)
			printf("Impossible\n");
		else
			printf("%d\n", ans);

	}
}