#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
	int a[25];
	a[1] = 1;
	a[2] = 2;
	for (int i = 3; i < 25; i++)
	{
		a[i] = a[i - 1] + a[i - 2];
		printf("%d\n", a[i]);
	}
}