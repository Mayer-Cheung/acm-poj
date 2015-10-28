#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int N, C, F, n;
struct cow
{
	int score, money;
}a[100010];
bool cmp(const cow& a, const cow& b)
{
	return a.score < b.score;
}
bool check(int mid)
{
	int sum = 0;
	int ans = 0;
	int less = 0;
	int total = 0;
	for (int i = 0; i < C; i++)
	{
		if (a[i].money > F - sum && total <= N)
			continue;
		else
		{
			total++;
			sum += a[i].money;
			if (a[i].score <= mid)
			{
				less++;
			}
			if (less == n)
			{
				ans = a[i].score;
			}
		}
	}

	return total == N && ans == mid;

}
int main()
{
	scanf("%d%d%d", &N, &C, &F);
	for (int i = 0; i < C; i++)
		scanf("%d%d", &a[i].score, &a[i].money);
	n = (N - 1) / 2;
	sort(a, a + C, cmp);
	int lb = -1, ub = a[C - 1].score + 1;
	while (lb <= ub)
	{
		int mid = (lb + ub) >> 1;
		if (check(mid))
			lb = mid + 1;
		else
			ub = mid - 1;
	}
	cout << check(20) << endl;
	cout << check(35) << endl;
	printf("%d\n", lb);
}