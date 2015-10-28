#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int n, m;
struct Sequence
{
	char str[55];
	int num;
}a[105];
bool cmp(const Sequence& a, const Sequence& b)
{
	return a.num < b.num;
}
void getNum(Sequence& a)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a.str[i] > a.str[j])
				a.num++;
		}
	}
}
int main()
{
	memset(a, 0, sizeof(a));
	scanf("%d %d\n", &n, &m);
	for (int i = 0; i < m; i++)
	{
		cin >> a[i].str;
		getNum(a[i]);
	}
	sort(a, a + m, cmp);
	for (int i = 0; i < m; i++)
		cout << a[i].str << "\n";
}