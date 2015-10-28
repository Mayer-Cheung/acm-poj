#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
bool check(int n)
{
	int sum = 0;
	while (n)
	{
		if (n & 1 == 1)
			sum--;
		else
			sum++;
		n >> 1;
	}
	return sum >= 0;
}
int main()
{
	for (int i = 1; i <= 100; i++)
	{
		printf("%d is %d\n", i, check(i));
	}
}