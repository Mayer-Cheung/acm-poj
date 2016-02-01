#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 105;
int a[MAXN][MAXN], row[MAXN], col[MAXN], n;

int main()
{
	while (scanf("%d", &n), n)
	{
		memset(a, 0, sizeof(a));
		memset(row, 0, sizeof(row));
		memset(col, 0, sizeof(col));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &a[i][j]);

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				row[i] += a[i][j];
				col[j] += a[i][j];
			}

		int cr = 0, cc = 0, index_row = 0, index_col = 0;

		for (int k = 0; k < n; k++)
		{
			if (row[k] & 1)
			{
				cr++;
				index_row = k;
			}
			if (col[k] & 1)
			{
				cc++;
				index_col = k;
			}
		}

		if (cr == 0 && cc == 0)
			printf("OK\n");
		else if (cr == 1 && cc == 1)
			printf("Change bit (%d,%d)\n", index_row + 1, index_col + 1);
		else
			printf("Corrupt\n");
	}
}