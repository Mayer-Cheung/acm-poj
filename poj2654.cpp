#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 205;
int k, n;

int win[MAXN], lose[MAXN];

void solve()
{
	for (int i = 0; i < k * (n - 1) * n / 2; i++)
	{
		int a, b;
		char s1[10], s2[10];
		scanf("%d %s %d %s", &a, s1, &b, s2);
		if (strcmp(s1, s2) == 0)
			continue;
		if (strcmp(s1, "rock") == 0)
		{
			if (strcmp(s2, "paper") == 0)
			{
				win[b]++;
				lose[a]++;
			}
			else
			{
				win[a]++;
				lose[b]++;
			}
		}
		else if (strcmp(s1, "paper") == 0)
		{
			if (strcmp(s2, "rock") == 0)
			{
				win[a]++;
				lose[b]++;
			}
			else
			{
				win[b]++;
				lose[a]++;
			}
		}
		else if(strcmp(s1, "scissors") == 0)
		{
			if (strcmp(s2, "rock") == 0)
			{
				win[b]++;
				lose[a]++;
			}
			else
			{
				win[a]++;
				lose[b]++;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (win[i] + lose[i] == 0)
			printf("-\n");
		else
			printf("%0.3lf\n", win[i] / ((1.0) * (win[i] + lose[i])));
	}
}

int main()
{
	int x = 0;
	while (scanf("%d", &n) && n)
	{
		if (x)
			printf("\n");		
		scanf("%d", &k);
		memset(win, 0, sizeof(win));
		memset(lose, 0, sizeof(lose));
		solve();
		x++;
	}
}