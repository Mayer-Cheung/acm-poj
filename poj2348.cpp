#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	int a, b;
	while (scanf("%d%d", &a, &b), a + b)
	{
		bool flag = true;
		for (;;)
		{
			if (a > b)
				swap(a, b);
			if (b % a == 0)
				break;
			if (b - a > a)
				break;
			b -= a;
			flag = !flag;
		}
		if (flag)
			printf("Stan wins\n");
		else
			printf("Ollie wins\n");
	}
}