#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{

	int cnt, n;
	scanf("%d", &n);
	int ans = 1;
	for (int i = 2; i * (i + 1) / 2 <= n; i++)
	{
		if ((n - i * (i + 1) / 2) % i == 0)
			ans++;
	}
	printf("%d\n",ans);
}