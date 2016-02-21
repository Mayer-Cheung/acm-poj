#include <iostream>
#include <cstdio>
#include <set>
#include <vector>

using namespace std;

int main()
{
	set<int> sB;
	vector<int> vec;
	int t;
	scanf("%d", &t);
	while (t--)
	{
		vec.clear();
		sB.clear();
		int a, b;
		int sumA = 0, sumB = 0;
		scanf("%d%d", &a, &b);
		for (int i = 0; i < 4; i++)
		{
			if (a % 10 != b % 10)
			{
				vec.push_back(a % 10);
				sB.insert(b % 10);
			}
			else
				sumA++;
			a /= 10;
			b /= 10;
		}

		for (int i = 0; i < vec.size(); i++)
			if (sB.find(vec[i]) != sB.end())
				sumB++;
		printf("%dA%dB\n", sumA, sumB);
	}

}