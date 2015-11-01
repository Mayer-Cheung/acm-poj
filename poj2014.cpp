#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	int max_w;
	int a, b, x;
	int cur = 0, tmp_h = 0, tmp_w = 0, cnt = 0;
	while (scanf("%d", &max_w), max_w)
	{
		cur = tmp_h = tmp_w = cnt = 0;
		while (scanf("%d%d", &a, &b) && a + b != -2)
		{
			if (cur + a > max_w)
			{
				tmp_w = max(tmp_w, cur);
				cur = 0;
				cnt += tmp_h;
				tmp_h = 0;
			}
			cur += a;
			tmp_h = max(tmp_h, b);
		}
		tmp_w = max(tmp_w, cur);
		printf("%d x %d\n", tmp_w, cnt + tmp_h);
	}
}