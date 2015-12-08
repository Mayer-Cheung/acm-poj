#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Student
{
	int vol;
	char name[10];
}s[10];

bool cmp(Student x, Student y)
{
	return x.vol < y.vol;
}

int main()
{
	int n;
	while (scanf("%d", &n) && n != -1)
	{
		for (int i = 0; i < n; i++)
		{
			int a, b, c;
			scanf("%d%d%d%s", &a, &b, &c, s[i].name);
			s[i].vol = a * b * c;
		}
		sort(s, s + n, cmp);
		printf("%s took clay from %s.\n", s[n - 1].name, s[0].name);
	}
}