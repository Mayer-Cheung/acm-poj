//简洁版， 另此题不可剪枝， 因为要字典序输出，剪枝wa
//剪枝就是将下一步可到达的点中，按照其可到达的点，从小到大排序，先访问下一步可能性少的点
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int p, q;
bool flag[30][30];
int road[905];
const int dir[8][2] = { /// 字典序最小的走法顺序  
    {-2,-1}, {-2,1}, {-1,-2},{-1,2},  
    {1,-2},{1,2},{2,-1},{2,1}};
struct Path
{
    int x, y;
}path[905];
bool dfs(int x, int y, int step)
{
    flag[x][y] = true;
    path[step].x = x;
    path[step].y = y;
    if (path == p * q)
        return true;

    int xt, yt;
    for (int i = 0; i < 8; i++)
    {
        xt = x + dir[i][0];
        yt = y + dir[i][1];
        if (1 <= xt && xt <= q && 1 <= yt && yt <= p && !flag[xt][yt])
        {
            if (dfs(xt, yt, step + 1))
                return true;
        }
    }
    flag[x][y] = false;
    return false;
}
int main()
{
    int t, cnt = 0;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &p, &q);
        memset(flag, 0, sizeof(flag));
        printf("Scenario #%d:\n", ++cnt);

        if (dfs(1, 1, 1))
        {
            for (int i = 1; i <= p * q; i++)
                printf("%c%d", (char)(path[i].x + 'A' - 1), path[i].y);
            printf("\n");
        }
        else
            printf("impossible\n");
        if　(t)
            printf("\n");
    }
}
//  my code 此题版
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int row, col;
bool flag[30][30];
int road[905];
const int dir[8][2] = { /// 字典序最小的走法顺序  
    {-2,-1}, {-2,1}, {-1,-2},{-1,2},  
    {1,-2},{1,2},{2,-1},{2,1}};
bool valid(int x, int y)
{
    return x >= 1 && x <= col && y >= 1 && y <= row && !flag[x][y];
}

struct node
{
    int x, y;
    node()
    {
        x = y = -1;
    }
    node (int a, int b)
    {
        x = a;
        y = b;

    }
};
node getNode(node n, int i)
{
    int a = n.x + dir[i][0];
    int b = n.y + dir[i][1];
    return node(a, b);
}
node numToNode(int k)
{
    int x = k % col;
    if (x == 0)
        x = col;
    int y = (k - 1) / row + 1;
    if (valid(x, y))
        return node(x, y);
}
int nodeToNum(node n)
{
    return (n.y - 1) * col + n.x;
}
void haha(int n)
{
    int x = n % col;
    if (x == 0)
        x = col;
    int y = (n - 1) / col + 1;
    printf("%c%d", x + 'A' - 1, y);
}
bool DFS(node start, int degr)
{
    if (degr == row * col)
    {
        road[degr] = nodeToNum(start);
        return true;
    }
    int a = start.x;
    int b = start.y;
    flag[a][b] = true;

    vector<node> sear;
    road[degr] = nodeToNum(start);

    for (int i = 0; i < 8; i++)
    {
        node n = getNode(start, i);
        if (valid(n.x, n.y))
            sear.push_back(n);
    }

    for (int i = 0; i < sear.size(); i++)
    {
        if (DFS(sear[i], degr + 1))
            return true;
    }
    flag[a][b] = false;
    return false;
}
int main()
{
    int t;
    scanf("%d", &t);
    int cnt = 0;
    while (t--)
    {
        printf("Scenario #%d:\n", ++cnt);
        scanf("%d%d", &row, &col);
        memset(flag, 0, sizeof(flag));
        node start = numToNode(1);
        if (DFS(start, 1) == true)
        {
            for (int i = 1; i <= col * row; i++)
                haha(road[i]);
            printf("\n");
        }
        else
            printf("impossible\n");
        if (t)
            printf("\n");
    }
}
//  my code 剪枝版
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int row, col;
bool flag[30][30];
int road[905];
const int dir[8][2] = { /// 字典序最小的走法顺序  
    {-2,-1}, {-2,1}, {-1,-2},{-1,2},  
    {1,-2},{1,2},{2,-1},{2,1}};
bool valid(int x, int y)
{
    return x >= 1 && x <= col && y >= 1 && y <= row && !flag[x][y];
}
int num(int x, int y)
{
    int total = 0;
    for (int i = 0; i < 8; i++)
    {
        int a = x + dir[i][0];
        int b = y + dir[i][1];
    if (valid(a, b))
        total++;    
    }

    return total;
}
struct node
{
    int x, y, sub;
    node()
    {
        x = y = sub = -1;
    }
    node (int a, int b)
    {
        x = a;
        y = b;
        sub = num(a, b);
    }
};
node getNode(node n, int i)
{
    int a = n.x + dir[i][0];
    int b = n.y + dir[i][1];
    return node(a, b);
}
bool cmp(node n, node m)
{
    return n.sub < m.sub;
}
node numToNode(int k)
{
    int x = k % col;
    if (x == 0)
        x = col;
    int y = (k - 1) / row + 1;
    if (valid(x, y))
        return node(x, y);
}
int nodeToNum(node n)
{
    return (n.y - 1) * col + n.x;
}
void haha(int n)
{
    int x = n % col;
    if (x == 0)
        x = col;
    int y = (n - 1) / col + 1;
    printf("%c%d", x + 'A' - 1, y);
}
bool DFS(node start, int degr)
{
    if (degr == row * col)
    {
        road[degr] = nodeToNum(start);
        return true;
    }
    int a = start.x;
    int b = start.y;
    flag[a][b] = true;

    vector<node> sear;
    road[degr] = nodeToNum(start);

    for (int i = 0; i < 8; i++)
    {
        node n = getNode(start, i);
        if (valid(n.x, n.y))
            sear.push_back(n);
    }
    sort(sear.begin(), sear.end(), cmp);

    for (int i = 0; i < sear.size(); i++)
    {
        if (DFS(sear[i], degr + 1))
            return true;
    }
    flag[a][b] = false;
    return false;
}
int main()
{
    int t;
    scanf("%d", &t);
    int cnt = 0;
    while (t--)
    {
        printf("Scenario #%d:\n", ++cnt);
        scanf("%d%d", &row, &col);
        memset(flag, 0, sizeof(flag));
        node start = numToNode(1);
        if (DFS(start, 1) == true)
        {
            for (int i = 1; i <= col * row; i++)
                haha(road[i]);
            printf("\n");
        }
        else
            printf("impossible\n");
        if (t)
            printf("\n");
    }
}