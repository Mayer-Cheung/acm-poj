#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 305;
vector<int> vec[MAXN];
bool used[MAXN];
int match[MAXN];
int n;

int find(int u)
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
	for (int i = 0; i < n; i++)
	{
		memset(used, 0, sizeof(used));
		if (find(i))
			ans++;
	}
	return ans;
}

int main()
{
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 0; i < n; i++)
			vec[i].clear();
		memset(used, 0, sizeof(used));
		memset(match, -1, sizeof(match));

		int t;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &t);
			for (int j = 0; j < t; j++)
			{
				int p, q;
				scanf("%d%d", &p, &q);
				vec[i].push_back(p * 12 + q);
			}
		}
		printf("%d\n", cal());
	}
}