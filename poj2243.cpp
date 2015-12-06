#include <iostream>
#include <cstdio>
#include <queue>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cstring>

using namespace std;

struct P
{
	int x, y, steps;
};

bool map[10][10];
int fx[8][2] = {1, 2, -1, 2, 2, 1, -2, 1, 2, -1, -2, -1, 1, -2, -1, -2};
queue<P> q;

int main()
{
	int n;
	P start, end;
	char s1[5], s2[5];
	while (scanf("%s%s", s1, s2) != EOF)
	{
		while (!q.empty())
			q.pop();
		memset(map, 0, sizeof(map));
		start.x = s1[0] - 'a';
		start.y = s1[1] - '1';
		end.x = s2[0] - 'a';
		end.y = s2[1] - '1';
		start.steps = 0;
		q.push(start);
		map[start.x][start.y] = 0;
		while (!q.empty())
		{
			P cur = q.front();
			q.pop();
			if (cur.x == end.x && cur.y == end.y)
			{
				printf("To get from %s to %s takes %d knight moves.\n", s1, s2, cur.steps);
				break;
			}
			for (int i = 0; i < 8; i ++)
			{
				P curr;
				curr.x = cur.x + fx[i][0];
				curr.y = cur.y + fx[i][1];
				curr.steps = cur.steps + 1;
				if (curr.x >= 8 || curr.y >= 8 || curr.x < 0 || curr.y < 0
					|| map[curr.x][curr.y] == true)
					continue;
				map[curr.x][curr.y] = true;
				q.push(curr);
			}
		}
	}
}