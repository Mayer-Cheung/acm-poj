#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int f0, f1, f2;
	while (scanf("%d%d%d", &f0, &f1, &f2) != EOF)
	{
		int a, b, c;
		a = (f2 - 2 * f1 + f0) / 2;
		b = (4 * f1 - f2 - 3 * f0) / 2;
		c = f0;
		int f3 = 9 * a + 3 * b + c;
		int f4 = 16 * a + 4 * b + c;
		int f5 = 25 * a + 5 * b + c;
		printf("%d %d %d\n", f3, f4, f5);
	}
}