#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

const int MAXN = 20005;
int wood[MAXN], n;

void solve()
{
	long long ans = 0;
	priority_queue<int, vector<int>, greater<int> > que;
	for (int i = 0; i < n; i++)
	{
		que.push(wood[i]);
	}
	while (que.size() > 1)
	{
		int l1 = que.top();
		que.pop();
		int l2 = que.top();
		que.pop();
		ans += l1 + l2;
		que.push(l1 + l2);
	}
	printf("%lld\n", ans);
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{	
		scanf("%d", &wood[i]);
	}
	solve();
}