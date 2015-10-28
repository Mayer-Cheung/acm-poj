#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int p, e, i, d;
	int test = 1;
	while (scanf("%d%d%d%d", &p, &e, &i, &d) && p + e + i + d != -4)
	{
		int j = d + 1;
		for (; j < 21252; j++) {
			if ((j - p) % 23 == 0) {
				break;
			}
		}
		for (; j < 21252; j += 23) {
			if ((j - e) % 28 == 0) {
				break;
			}
		}
		for (; j < 21252; j += 23* 28) {
			if ((j - i) % 33 == 0) {
				break;
			}
		}
		printf("Case %d: the next triple peak occurs in %d days.\n", test++, j - d);
	}
}