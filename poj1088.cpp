#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 105;

int ans[MAXN][MAXN];
int map[MAXN][MAXN];
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};

int n, m;

int dp(int i, int j)
{
    if (ans[i][j] > 0)
        return ans[i][j];

    int t_max = 0;
    for (int t = 0; t < 4; t++)
    {
        int ti = i + dir[t][0];
        int tj = j + dir[t][1];
        if (ti > 0 && ti <= n && tj > 0 && tj <= m)
        {
            if (map[ti][tj] < map[i][j])
                t_max = max(t_max, dp(ti, tj));
        }
    }
    return ans[i][j] = t_max + 1;
}

int main()
{
    while (scanf("%d%d", &n, &m) != EOF)
    {
        int t_ans = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                scanf("%d", &map[i][j]);

        for (int i = 0; i < MAXN; i++)
            for (int j = 0; j < MAXN; j++)
                ans[i][j] = 0;

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                ans[i][j] = dp(i, j);
                t_ans = max(t_ans, ans[i][j]);
            }

        printf("%d\n", t_ans);
    }
}