#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 10000 + 5;
int a[MAXN], s[MAXN], mod[MAXN], n;

void print(int s, int t)
{
	printf("%d\n", t + 1 - s);
	for (int i = s; i <= t; i++)
		printf("%d\n", a[i]);
}

//  if sum[i] % n = sum[j] % n, print(i+ 1, j)

int main()
{
	scanf("%d", &n);
	memset(a, 0, sizeof(a));
	memset(s, 0, sizeof(s));
	memset(mod, 0, sizeof(mod));
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		s[i] = s[i - 1] + a[i];
		if (s[i] % n == 0)
		{
			print(1, i);
			break;
		}
		else if (!mod[s[i] % n])
		{
			mod[s[i] % n] = i;
		}
		else {
			print (mod[s[i] % n] + 1, i);
			break;
		}
	}

}