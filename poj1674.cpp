#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 10005;
int a[MAXN];
bool oc[MAXN], stk[MAXN];

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, sum = 0, tmp, now;
		memset(oc, 0, sizeof(oc));
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);

		for (int i = 1; i <= n; i++)
		{
			tmp = 0;
			if (!oc[i])
			{
				memset(stk, 0, sizeof(stk));
				oc[i] = true;
				stk[i] = true;
				tmp++;
				now = i;
				while (stk[a[now]] == false)
				{
					oc[a[now]] = true;
					tmp++;
					stk[a[now]] = true;
					now = a[now];
				}
				sum += tmp - 1;
			}
		}
		printf("%d\n", sum);
	}
}