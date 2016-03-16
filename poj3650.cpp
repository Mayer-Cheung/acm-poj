#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	string str;
	while (true)
	{
		getline(cin, str);
		if (str[0] == '#')
			break;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == ' ')
				printf("%%20");
			else if (str[i] == '!')
				printf("%%21");
			else if (str[i] == '$')
				printf("%%24");
			else if (str[i] == '%')
				printf("%%25");
			else if (str[i] == '(')
				printf("%%28");
			else if (str[i] == ')')
				printf("%%29");
			else if (str[i] == '*')
				printf("%%2a");
			else
				printf("%c", str[i]);
		}
		printf("\n");
	}
}