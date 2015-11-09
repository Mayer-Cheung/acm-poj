#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int main()
{
	int room[401];
	int test, move_time, i, j, temp;
	int from[200], to[200];
	scanf("%d", &test);
	while (test--)
	{
		memset(room, 0, sizeof(room));
		scanf("%d", &move_time);
		for (i = 0; i < move_time; i++)
		{
			scanf("%d%d", &from[i], &to[i]);
			if (from[i] > to[i])
				swap(from[i], to[i]);
			if (from[i] % 2 == 1)
				from[i]++;
			if (to[i] % 2 == 1)
				to[i]++;
			for (temp = from[i]; temp <= to[i]; temp++)
				room[temp]++;
		}
		sort(room, room + 401);
		printf("%d\n", room[400] * 10);
	}
	return 0;
}