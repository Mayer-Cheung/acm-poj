#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

#define lchild rt << 1, l, m
#define rchild rt << 1 | 1, m + 1, r

using namespace std;

const int MAXN = 262144;

int n, q;

struct Node
{
	int L, R;
	long long sum, inc;
	Node()
	{
		L = R = sum = inc = 0;
	}
}T[MAXN];

void push_up(int rt)
{
	T[rt].sum = T[rt << 1].sum + T[rt << 1 | 1].sum;
}

void init(int rt = 1, int l = 1, int r = n)
{
	if (l == r)
	{ 
		scanf("%lld", &T[rt].sum);
		return;
	} 
	int m = (l + r) >> 1;
	init(lchild);
	init(rchild);
	push_up(rt);
}

void push_down(int rt, int len)
{
	T[rt << 1].sum += T[rt].inc * (len - (len >> 1));
	T[rt << 1].inc += T[rt].inc;
	T[rt << 1 | 1].sum += T[rt].inc * (len >> 1);
	T[rt << 1 | 1].inc += T[rt].inc;
	T[rt].inc = 0;
}

void update(int L, int R, int delta, int rt = 1, int l = 1, int r = n)
{
	if (L <= l && r <= R)
	{
		T[rt].sum += delta * (r - l + 1);
		T[rt].inc += delta;
		return;
	}
	if (T[rt].inc)
		push_down(rt, r - l + 1);
	int m = (l + r) >> 1;
	if (L <= m)
		update(L, R, delta, lchild);
	if (R > m)
		update(L, R, delta, rchild);
	push_up(rt);
}

long long query(int L, int R, int rt = 1, int l = 1, int r = n)
{
	if (L <= l && r <= R)
		return T[rt].sum;
	if (T[rt].inc)
		push_down(rt, r - l + 1);
	int m = (l + r) >> 1;
	long long ret = 0;
	if (L <= m)
		ret += query(L, R, lchild);
	if (R > m)
		ret += query(L, R, rchild);
	return ret;
}

int main()
{
	scanf("%d%d", &n, &q);
	memset(T, 0, sizeof(T));
	init(1, 1, n);
	while (q--)
	{
		char c;
		int l, r, incre;
		cin >> c;
		if (c == 'Q')
		{
			scanf("%d%d", &l, &r);
			printf("%lld\n",query(l, r));
		}
		else
		{
			scanf("%d%d%d", &l, &r, &incre);
			update(l, r, incre);
		}
	}
}