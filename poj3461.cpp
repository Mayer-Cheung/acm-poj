#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXW = 10010;
const int MAXT = 1000010;

int match(char w[], char s[], int next[])
{
	int cnt = 0;
	int slen = strlen(s);
	int wlen = strlen(w);
	int p = 0, cur = 0;
	while (cur < slen)
	{
		if (s[cur] == w[p])
		{
			cur++;
			p++;
		}
		else if (p >= 0)
		{
			p = next[p];
		}
		else
		{
			cur++;
			p = 0;
		}
		if (p == wlen)
		{
			cnt++;
			p = next[p];
		}
	}
	return cnt;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		char w[MAXW], t[MAXT];
		scanf("%s%s", w, t);
		int suffix[MAXW];
		suffix[0] = -1;
		suffix[1] = 0;
		int p = 0;
		for (int cur = 2; cur <= strlen(w); cur++)
		{
			while (p >= 0 && w[p] != w[cur - 1])
				p = suffix[p];
			suffix[cur] = ++p;
		}
		printf("%d\n", match(w, t, suffix));
	}
}