#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

const double INF = 1.0e15;
const double walk_v = (10000.0/60.0);
const double car_v  = (40000.0/60.0);
const int maxn = 200 + 10;
int n;
double map[maxn][maxn];

struct Point
{
    double x, y;
}p[maxn];

double get_time(int i, int j, double v)
{
    return sqrt((p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y)) / v;
}

int main()
{
    for (int i = 0; i < maxn; i++)
    	for (int j = 0; j< maxn; j++)
        	map[i][j] = i==j ? 0 : -1;

    scanf("%lf%lf%lf%lf",&p[0].x,&p[0].y,&p[1].x,&p[1].y);
    n=2;
    double pre_x=-1;
    while (scanf("%lf%lf", &p[n].x, &p[n].y) == 2)
    {
        if (pre_x != -1 && p[n].x != -1)
        {
            map[n-1][n] = map[n][n-1] = get_time(n-1, n, car_v);
        }
        pre_x = p[n].x;
        if (p[n].x !=-1) 
        	 ++n;
    }
    for (int i = 0; i < n; i++)
    	for (int j = i + 1; j < n; j++)
    		if (map[i][j] == -1)
        		map[i][j] = map[j][i] = get_time(i, j, walk_v);

    //Floyd
    for (int k = 0; k < n; k++)
    	for (int i = 0; i < n; i++)
    		for (int j = 0; j < n; j++)
    			if (map[i][k] != -1 && map[k][j] != -1)
        			map[i][j] = min(map[i][j], map[i][k] + map[k][j]);

    printf("%.0f\n", map[0][1]);
}
