#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
int a[26], b[26];
int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	for (int i = 0; i < s1.length(); i++)
		a[s1[i] - 'A']++;
	for (int i = 0; i < s2.length(); i++)
		b[s2[i] - 'A']++;
	sort(a, a + 26);
	sort(b, b + 26);
	bool ok = true;
	for (int i = 0; i < 26; i++)
		if (a[i] != b[i])
		{
			ok = false;
			break;
		}
	if (ok)
		printf("YES\n");
	else
		printf("NO\n");
}