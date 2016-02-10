//  greedy
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 5005;
bool used[MAXN];

struct Stick
{
	int l, w;
	bool operator<(const Stick& a) const
	{
		return l == a.l ? w < a.w : l < a.l;
	}
}s[MAXN];

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d%d", &s[i].l, &s[i].w);
		sort(s, s + n);

		memset(used, 0, sizeof(used));
		int res = 0;
		for (int i = 0; i < n; i++)
		{
			int temp = s[i].w;
			if (!used[i])
			{
				for (int j = i + 1; j < n; j++)
				{
					if (s[j].w >= temp && !used[j])
					{
						temp = s[j].w;
						used[j] = true;
					}
				}
				res++;
			}
		}
		printf("%d\n", res);
	}
}

//  dp
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 5005;
int dp[MAXN];

struct Stick
{
	int l, w;
	bool operator<(const Stick& a) const
	{
		return l == a.l ? w < a.w : l < a.l;
	}
}s[MAXN];

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d%d", &s[i].l, &s[i].w);
		sort(s, s + n);

		for (int i = 0; i < n; i++)
			dp[i] = 1;
		int res = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (s[j].w > s[i].w)
					dp[i] = max(dp[i], dp[j] + 1);
			}
			res = max(res, dp[i]);
		}
		printf("%d\n", res);
	}
}