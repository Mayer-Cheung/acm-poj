#include <iostream>
#include <cstdio>
#include <set>
#include <cstring>
using namespace std;
 long long a[120][2];
int main()
{
	int p, t;
	set<pair< long long,  long long> > res;
	scanf("%d%d", &p, &t);
	int tp, tt;
	memset(a, 0, sizeof(0));
	while (scanf("%d%d", &tp, &tt) != EOF)
	{
		if (tt <= 50)
			a[tp][1] |= (1 << tt);
		else
			a[tp][0] |= (1 << (tt - 50));
	}
	for (int i = 1; i <= p; i++)
		res.insert(make_pair(a[i][0], a[i][1]));
	printf("%d\n", res.size());
}