#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
int str2num(string a)
{
	int num = 0;
	int len = a.length();
	for (int i = 0; i < len; i++)
	{
		num *= 10;
		num += a[i] - '0';
	}
	return num;
}

string tostring(int a)
{
	string str = "";
	while (a)
	{
		str += (a % 10) + '0';
		a /= 10;
	}
	if (str[0] == '0')
	{
		int i = 0;
		while (str[i++] == '0');
		str.erase(str. begin(), str.begin() + i - 1);
	}
	return str;
}
int main()
{
	int test;
	scanf("%d", &test);
	while (test--)
	{
		string a, b;
		cin >> a >> b;
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		int c = str2num(a) + str2num(b);
		cout << tostring(c) << endl;
	}
}