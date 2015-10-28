#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	double sum = 0, temp;
	for (int i = 0; i < 12; i++)
	{
		scanf("%lf", &temp);
		sum += temp;
	}
	printf("$%.2lf\n", sum / 12.0);
}