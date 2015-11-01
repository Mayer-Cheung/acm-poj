#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct ADT
{
	int s, t;	
} sec[5010];

bool cmp(ADT a, ADT b)
{
	return a.s < b.s || a.t < b.t;
}

int l, m;

int main()
{
	int i, S, T;
	while (scanf("%d%d", &l, &m), l + m)
	{
		for (i = 0; i < m; i++)
			scanf("%d%d", &sec[i].s, &sec[i].t);
		sort(sec, sec + m, cmp);
		S = 0;
		for (i = 0; i < m; i++)
		{
			if (sec[i].t > S)
			{
				if (sec[i].s > S)
					S = sec[i].s - 1;
				l -= sec[i].t - S;
				S = sec[i].t;
			}
		}
		printf("%d\n", l + 1);
	}
}