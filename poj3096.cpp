#include <iostream>
#include <string>
#include <cstdio>
#include <set>
using namespace std;
bool check(string str)
{
	int len = str.length();
	for (int i = 0; i <= len - 2; i++)
	{
		set<string> s;
		string a = "";
		for (int k = 0; k + i + 1 < len; k++)
		{
			a += str[k];
			a += str[k + i + 1];
			if (s.count(a) != 0)
				return false;
			else
			{
				s.insert(a);
				a = "";
			}
		}
	}
	return true;
}
int main()
{
	string str;
	while (true)
	{
		cin >> str;
		if (str == "*")
			break;
		if (check(str))
			cout << str << " is surprising.\n";
		else
			cout << str << " is NOT surprising.\n";
	}
}