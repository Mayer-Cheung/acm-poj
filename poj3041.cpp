#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 505;
vector<int> vec[MAXN];
bool used[MAXN];
int match[MAXN];
int n, m;

bool find(int u)
{
	for (int i = 0; i < vec[u].size(); i++)
	{
		if (!used[vec[u][i]])
		{
			used[vec[u][i]] = true;
			if (match[vec[u][i]] == -1 || find(match[vec[u][i]]))
			{
				match[vec[u][i]] = u;
				return true;
			}
		}
	}
	return false;
}

int cal()
{
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		memset(used, 0, sizeof(used));
		if (find(i))
			ans++;
	}
	return ans;
}

int main()
{
	scanf("%d%d", &n, &m);
	memset(match, -1, sizeof(match));
	for (int i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		vec[x].push_back(y);
	}
	printf("%d\n", cal());
}