#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
	char a[6];
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%s", a);
		int minute = 0, la = strlen(a), hour = 0;
		minute += a[la - 1] - '0';
		minute += 10 * (a[la - 2] - '0');

		if (minute != 0)
		{
			printf("0\n");
			continue;
		}
		if (la == 4)
		{
			hour += a[0] - '0';
		}
		else
		{
			hour += 10 * (a[0] - '0');
			hour += a[1] - '0';
		}
		if (hour <= 12)
			printf("%d\n", hour + 12);
		else
			printf("%d\n", hour - 12);
	}
}