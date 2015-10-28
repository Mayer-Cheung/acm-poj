#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int n, k;
int a[100010];
bool check(int mid)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (mid >= a[i])
			continue;
		else
		{
			count += ceil((double)(a[i] - mid) / (k - 1));
			if (count > mid)
				return false;
		}
	}
	return count <= mid;
}
int main()
{
	scanf("%d", &n);
	int maxx = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		maxx = max(maxx, a[i]);
	}
	scanf("%d", &k);
	if (k == 1)
		printf("%d\n", maxx);
	else {
		int lb = 0, ub = maxx;
		while (ub > lb)
		{
			int mid = (lb + ub) / 2;
			if (check(mid))
				ub = mid;
			else
    	        lb = mid + 1;
		}
		printf("%d\n", lb);
	}
}