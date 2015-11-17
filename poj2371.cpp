#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100005;

int n, a[MAXN], k;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	sort(a, a + n);

	char s[100];
	scanf("%s", s);

	scanf("%d", &k);

	while (k--)
	{
		int x;
		scanf("%d", &x);
		printf("%d\n", a[x - 1]);
	}
}

#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 5005;
int n, a[MAXN], k;

int main()
{
	scanf("%d", &n);
	memset(a, 0, sizeof(a));
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		a[x]++;
	}
	char s[100];
	scanf("%s", s);
	scanf("%d", &k);
	while (k--)
	{
		int x, cnt = 0;
		scanf("%d", &x);
		for (int i = 0; i < MAXN; i++)
		{
			cnt += a[i];
			if (cnt >= x)
			{
				printf("%d\n", i);
				break;
			}
		}
	}
}