#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	int t;
	string str, s1, s2;
	scanf("%d", &t);
	while (t--)
	{
		cin >> str;
		int co1 = 0, cst1 = 0, co2 = 0, cst2 = 0, temp = 0;
		int sign = 1, segment = find(str.begin(), str.end(), '=') - str.begin();
		s1 = str.substr(0, segment);
		s2 = str.substr(segment + 1, str.length() - s1.length() - 1);
		for (int i = 0; i < s1.length(); i++)
		{
			if (i == 0 && s1[i] == '+')
				sign = 1;
			else if (i == 0 && s1[i] == '-')
				sign = -1;
			else
			{
				if (s1[i] == 'x')
				{
					if (temp == 0)
					{
						co1 += sign * 1;
					}
					else
					{
						co1 += sign * temp;
					}
					temp = 0;
					sign = 1;
				}
				else if (s1[i] == '+' || s1[i] == '-')
				{
					cst1 += sign * temp;
					temp = 0;
					sign = s1[i] == '+' ? 1 : -1;
				}
				else
				{
					temp = 10 * temp + s1[i] - '0';
				}
			}
		}
		if (s1[s1.length() - 1] != 'x')
			cst1 += temp * sign;
		temp = 0, sign = 1;


		for (int i = 0; i < s2.length(); i++)
		{
			if (i == 0 && s2[i] == '+')
				sign = 1;
			else if (i == 0 && s2[i] == '-')
				sign = -1;
			else
			{
				if (s2[i] == 'x')
				{
					if (temp == 0)
					{
						co2 += sign * 1;
					}
					else
					{
						co2 += sign * temp;
					}
					temp = 0;
					sign = 1;
				}
				else if (s1[i] == '+' || s1[i] == '-')
				{
					cst2 += sign * temp;
					temp = 0;
					sign = s2[i] == '+' ? 1 : -1;
				}
				else
				{
					temp = 10 * temp + s2[i] - '0';
				}
			}
		}
		if (s2[s1.length() - 1] != 'x')
			cst2 += temp * sign;
		co1 -= co2;
		cst2 -= cst1;
		if (co1 == 0 && cst2 == 0)
			printf("IDENTITY\n");
		else if (co1 == 0 && cst2 != 0)
			printf("IMPOSSIBLE\n");
		else
			printf("%.0f\n", floor(cst2 * 1.0 / co1));
	}
}