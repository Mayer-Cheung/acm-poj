#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int pos[10010];

int main() {
	int n;
	while (~scanf("%d", &n)) 
	{
		for (int i = 0; i < n; ++i)
			scanf("%d", &pos[i]);
		sort(pos, pos + n);
		long long int ret = 0;
		for (int i = 0; i < n - 1; ++i)
			ret += (long long int)(pos[i + 1] - pos[i]) * (long long int)(n - 1 - i) * (i + 1);
		printf("%lld\n", ret << 1);
	}
	return 0;
}