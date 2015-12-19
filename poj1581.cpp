#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	int n;
	int wsol = 0, wpt = 0;
	string wname = "";

	scanf("%d", &n);
	while (n--)
	{
		string name;
		int sol = 0, pt = 0, sub = 0, time = 0;
		cin >> name;
		for (int i = 0; i < 4; i++)
		{
			cin >> sub >> time;
			if (time > 0)
			{
				++sol;
				pt += (sub - 1) * 20 + time;
			}
		}
		if (sol > wsol || sol == wsol && wpt > pt)
		{
			wname = name;
			wsol = sol;
			wpt = pt;
		}
	}
	cout << wname << " " << wsol << " " << wpt << "\n";
}