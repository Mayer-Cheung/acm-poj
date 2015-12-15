#include <cstdio>
#include <cmath>
#include <cstdlib>

using namespace std;

int a[31270];
long long b[31270];

void init()
{
    int i, x = 10, cnt = 1;
    a[0] = 0;
    b[0] = 0;
    for (i = 1; i < 31270; i++)
    {
        if (i < x)
        {
            a[i] = a[i - 1] + cnt;
        }
        else
        {
            x *= 10;
            cnt++;
            a[i] = a[i - 1] + cnt;
        }
        b[i] = b[i - 1] + a[i];
    }
}

int check(int a)
{
    int i = 1;
    while (b[i] < a)
    {
        i++;
    }
    return i - 1;
}
int main()
{
    init();
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, i, j;
        scanf("%d", &n);
        int x = check(n);
        int cnt = n - b[x], len = 0;
        for (i = 1; len < cnt; i++)
        {
            len += (int)log10((double)i) + 1;
        }
        printf("%d\n", (i - 1) / (int)pow((double)10, len - cnt) % 10);
    }
    return 0;
}
