#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXN = 50005;

int a[MAXN];
struct Node
{
	int L, R;
	int sum, inc;
}T[MAXN * 3];

void init(int root, int l, int r)
{
	T[root].L = l, T[root].R = r;
	if (l == r)
	{
		T[root].sum = a[l];
		T[root].inc = 0;
		return;
	}
	else
	{
		int mid = (l + r) >> 1;
		init(root<<1, l, mid);
		init(root<<1|1, mid+1, r);
		T[root].sum = T[root<<1].sum + T[root<<1|1].sum;
		T[root].inc = 0;
	}
}

int query(int root, int l, int r)
{
	if (T[root].L == l && T[root].R == r)
		return T[root].nMax;
	else
	{
		int mid = (T[root].L+T[root].R) >> 1;
		if (r <= mid)
			return get_max(root<<1, l, r);
		else if (l > mid)
			return get_max(root<<1|1, l, r);
		else
		{
			return max(get_max(root<<1, l, mid), get_max(root<<1|1, mid+1, r));
		}
	}
}

int main()
{
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	memset(T, 0, sizeof(T));
	init(1, 1, n);
	while (q--)
	{
		char c;
		int l, r, incre;
		scanf("%c", &c);
		if (c == 'Q')
		{
			scanf("%d%d", &l, &r);
			printf("%d\n",query(1, l, r));
		}
		else
		{
			scanf("%d%d%d", &l, &r, &incre);
			update(1, l, r, incre);
		}
	}
}