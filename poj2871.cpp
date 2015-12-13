#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	double prev, cur;
	scanf("%lf", &prev);
	while (true)
	{
		scanf("%lf", &cur);
		if (cur == 999)
			break;
		printf("%.2lf\n", cur - prev);
		prev = cur;
	}
	printf("End of Output\n");
}