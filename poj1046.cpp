#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

struct Point
{
	int x, y, z;
}a[17];

double dist(Point a, Point b)
{
	return (sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z)));
}

int main()
{
	for (int i = 0; i < 16; i++)
		scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
	while (scanf("%d%d%d", &a[16].x, &a[16].y, &a[16].z) && a[16].x + a[16].y + a[16].z != -3)
	{
		double dis = 100000;
		int a1, b1, c1;
		for (int i = 0; i < 16; i++)
		{
			if (dist(a[16], a[i]) < dis)
			{
				dis = dist(a[16], a[i]);
				a1 = a[i].x, b1 = a[i].y, c1 = a[i].z;
			}
		}
		printf("(%d,%d,%d) maps to (%d,%d,%d)\n", a[16].x, a[16].y, a[16].z, a1, b1, c1);
	}
}