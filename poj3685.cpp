#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
long long cal(long long i, long long j)
{
	return i * i + 100000 * i + j * j- 100000 * j + i * j;
}
int main()
{
	int t;
	long long n, m;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%lld%lld", &n, &m);
		long long lb = -1e13, ub = 1e13;
		long long mid, ans;

		while (lb <= ub)
		{
			mid = (lb + ub) >> 1;
			long long cnt = 0;
			for (int col = 1; col <= n; col++)
			{
				long long ll = 1, rr = n, mmid;
				long long tmp = 0;
				while (rr >= ll)
				{
					mmid = (rr + ll) >> 1;
					long long res = cal(mmid, col);
					if (res <= mid)
					{
						tmp = mmid;
						ll = mmid + 1;
					}
					else
						rr = mmid - 1;
				}
				cnt += tmp;
			}
			if (cnt < m)
			{
				lb = mid + 1;
			}
			else
			{
				ans = mid;
				ub = mid - 1;
			}
		}
		printf("%lld\n", ans);
	}
}