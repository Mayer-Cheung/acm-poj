#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct table
{
	int end[101];
	int wait_time[101];	
};
int main()
{
	int t[3], n, cl, minute, time, people;
	char s[10];
	while (true)
	{
		table tab[3];
		int k[3] = {1, 1, 1}, sum = 0;
		for (n = 0; n < 3; n++)
		{
			memset(tab[n].end, 0, sizeof(tab[n].end);
			memset(tab[n].wait_time, 0, sizeof(tab[n].wait_time);
		}

		cin >> t[0] >> t[1] >> t[2];
		getchar();
		if (t[0]] + t[1] + t[2])
			break;
		while (true)
		{
			gets(s);
			if (s[0] == '#')
				break;
			cl = 10 * (s[0] - '0') + (s[1] - '0');
			minute = 10 * (s[3] - '0') + (s[4] - '0');
			time = 60 * (cl - 8) + minute;
			people = s[6] - '0';
			n = (people - 1) / 2;
		}
	}
}