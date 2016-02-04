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
	int nMin, nMax;
}T[MAXN * 3];

void init(int root, int l, int r)
{
	T[root].L = l, T[root].R = r;
	if (l == r)
	{
		T[root].nMax = T[root].nMin = a[l];
		return;
	}
	else
	{
		int mid = (l + r) >> 1;
		init(root<<1, l, mid);
		init(root<<1|1, mid+1, r);
		T[root].nMax = max(T[root<<1].nMax, T[root<<1|1].nMax);
		T[root].nMin = min(T[root<<1].nMin, T[root<<1|1].nMin);
	}
}

int get_max(int root, int l, int r)
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
int get_min(int root, int l, int r)
{
	if (T[root].L == l && T[root].R == r)
		return T[root].nMin;
	else
	{
		int mid = (T[root].L+T[root].R) >> 1;
		if (r <= mid)
			return get_min(root<<1, l, r);
		else if (l > mid)
			return get_min(root<<1|1, l, r);
		else
		{
			return max(get_min(root<<1, l, mid), get_min(root<<1|1, mid+1, r));
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
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", get_max(1, l, r) - get_min(1, l, r));
	}
}