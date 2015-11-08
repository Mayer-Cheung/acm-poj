#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int a[6];
int main()
{
	while (true)
	{
		bool flag = false;
		for (int i = 0; i < 6; i++)
		{
			scanf("%d", &a[i]);
		}
		if (a[0] + a[1] + a[2] + a[3] + a[4] + a[5] == 0)
			break;
		int sum = 0;
		sort(a, a + 6);
		for (int i = 1; i < 5; i++)
			sum += a[i];
		if (sum % 4 == 0)
			printf("%d\n", sum / 4);
		else if (sum % 2 == 0)
			printf("%.1f\n", sum / 4.0);
		else
			printf("%.2f\n", sum / 4.0);
	}
}