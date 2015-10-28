#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int N, M;
int a[100010];
bool check(int n)
{
	int temp_sum = 0;
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		if (a[i] > n)
			return false;
		else
		{
			temp_sum += a[i];
			if (temp_sum > n)
			{
				temp_sum = a[i];
				count++;
			}
		}
	}
	return ++count <= M;
}
int main()
{
	scanf("%d%d", &N, &M);
	int lb = -1, ub = 0;	
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
		if (lb < a[i])
			lb = a[i];
		ub += a[i];
	}

	while (ub > lb)
	{
		int mid = (lb + ub) / 2;
		if (check(mid))
			ub = mid;
		else
			lb = mid + 1;
	}
	printf("%d\n", ub); 
}