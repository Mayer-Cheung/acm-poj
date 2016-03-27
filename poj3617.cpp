#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 2005;
char str[MAXN];

int main()
{
	int n;
	char nb;
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++)
		cin >> str[i];
	int begin = 0, end = n - 1;
	int cnt = 0;
	while (begin <= end)
	{
		bool left = false;
		for (int i = 0; begin + i <= end - i; i++)
		{
			if (str[begin + i] < str[end - i])
			{
				left = true;
				break;
			}
			else if (str[begin + i] > str[end - i])
			{
				left = false;
				break;
			}
		}
		if (left)
			putchar(str[begin++]);
		else
			putchar(str[end--]);
		cnt++;
		if (cnt % 80 == 0)
		{
			putchar('\n');
		}
	}

}