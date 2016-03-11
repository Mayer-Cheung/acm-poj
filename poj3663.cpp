#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 20000 + 5;
int cow[MAXN];

int main()
{
	int n, s;
	scanf("%d%d", &n, &s);
	for (int i = 0; i < n; i++)
		scanf("%d", &cow[i]);
	sort(cow, cow + n);
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += upper_bound(cow + i + 1, cow + n, (s - cow[i])) - (cow + i + 1);
	printf("%d\n", sum);
}