#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	int n, m, k;
	int sum = 0;
	int a[15], b[15];
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < k; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < k; i++)
		scanf("%d", &b[i]);
	for (int i = 0; i < k; i++)
		sum += abs(a[i] - b[i]);
	printf("%d\n", sum / 2);
}