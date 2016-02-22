#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1005;
int a[MAXN];

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, sum = 0;

		scanf("%d", &n);

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			sum += a[i];
		}
		double avg = (double)sum / n;
		int cnt = 0;
		for (int i = 0; i < n; i++)
			if (a[i] > avg)
				cnt++;
		printf("%.3f%%\n", (double)cnt / n * 100);

	}
}