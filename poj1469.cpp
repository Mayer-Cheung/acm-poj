#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int P = 105;
const int N = 305;

int map[P][N];
int match[N];
bool used[N];
int p, n;

bool find(int u)
{
	for (int i = 1; i <= n; i++)
	{
		if (!used[i] && map[u][i])
		{
			used[i] = true;
			if (match[i] == -1 || find(match[i]))
			{
				match[i] = u;
				return true;
			}
		}
	}
	return false;
}

int cal()
{
	int sum = 0;
	for (int i = 1; i <= p; i++)
	{
		memset(used, 0, sizeof(used));
		if (find(i))
			sum++;
	}
	return sum;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		memset(map, 0, sizeof(map));
		memset(match, -1, sizeof(match));
		scanf("%d%d", &p, &n);
		for (int i = 1; i <= p; i++)
		{
			int num;
			scanf("%d", &num);
			for (int j = 1; j <= num; j++)
			{
				int tmp;
				scanf("%d", &tmp);
				map[i][tmp] = 1;
			}
		}
		int ans = cal();
		if (ans == p)
			printf("YES\n");
		else
			printf("NO\n");
	}
}