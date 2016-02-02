#include <iostream>
#include <cstdio>

using namespace std;

const char p[][5] = {"``", "''"};

int main()
{
	int k = 0;
	char c;
	while ((c = getchar()) != EOF)
	{
		if (c == '"')
		{
			printf("%s", p[k]);
			k = !k;
		}
		else
			putchar(c);
	}
}