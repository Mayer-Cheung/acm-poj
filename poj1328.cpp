#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int n, d;
int test = 0;
struct Island
{
	double left, right;
}a[1005];
bool cmp(const Island& a, const Island& b)
{
	return a.left < b.left;
}

int solve()
{
	int ans = 1;
	double pos = a[0].right;
	for (int i = 1; i < n; i++)
	{
		if (a[i].left > pos)
		{
			ans++;
			pos = a[i].right;
		}
		else
		{
			if (a[i].right < pos)
				pos = a[i].right
		}
	}
	return ans;
}

int main()
{
	while (scanf("%d%d", &n, &d) && n + d)
	{
		bool flag = false;
		int x, y;
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", &x, &y);
			if (!flag && (y <= d))
			{
				double temp = sqrt(double(d * d - y * y));
				a[i].left = x - temp;
				a[i].right = x + temp;
			}
			else
			{
				flag = true;
			}
		}
		if (flag)
		{
			printf("Case %d: -1\n", ++test);
			continue;
		}
		else
		{
			sort(a, a + n, cmp);
			printf("Case %d: %d\n", ++test, solve());
		}
	}
}