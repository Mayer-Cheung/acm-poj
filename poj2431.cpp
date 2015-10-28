#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
int n;
struct City
{
	int a, b;
}city[10010];
bool cmp(const City& x, const City& y)
{
	return x.a < y.a;
}
int l, p;
void solve()  //  use the priority queue
{
	int ans = 0, tank = p, pos = 0;
	priority_queue<int> q;
	for (int i = 0; i <= n; i++)
	{
		int d = city[i].a - pos;  //  distance to next city
		while (tank < d)  //  need to go to the gas station
		{
			if (q.empty())  //  no gas station to use
			{
				printf("-1\n");  //  cannot go to the final city
				return;
			}
			//  need to use the gas station
			tank += q.top();
			ans++;
			q.pop();
		}
		//  already get to the next city
		tank -= d;
		pos = city[i].a;
		q.push(city[i].b);
	}
	printf("%d\n", ans);
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &city[i].a, &city[i].b);
	scanf("%d%d", &l, &p);
	for (int i = 0; i < n; i++)
		city[i].a = l - city[i].a;
	city[n].a = l;
	city[n].b = 0;
	//  without sort will cause wrong answer.
	sort(city, city + n + 1, cmp);
	solve();
}