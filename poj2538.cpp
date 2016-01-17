#include <iostream>
#include <string>
using namespace std;

int main()
{
	string keyboard = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;\'ZXCVBNM,./";
	string s;

	while (getline(cin, s))
	{
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] != ' ')
				cout << keyboard[keyboard.find(s[i]) - 1];
			else
				cout << s[i];
		}
		cout << endl;
	}
	return 0;
}
