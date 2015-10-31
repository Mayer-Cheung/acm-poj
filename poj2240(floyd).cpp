//  floyd-warshall algorithm
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <string>
#include <cstring>

using namespace std;

double board[35][35];
map<string, int> a;
int main()
{
	int n, m;
	int t = 1;
	while (scanf("%d", &n), n)
	{
		string src, des;
		double rate;
		memset(board, 0, sizeof(board));
		a.clear();
		for (int i = 1; i <= n; i++)
		{
			cin >> src;
			a[src] = i;
			board[i][i] = 1;  //  must initialize here, since the input contain some same type of exchange
		}

		scanf("%d", &m);
		for (int i = 1; i <= m; i++)
		{
			cin >> src >> rate >> des;
			board[a[src]][a[des]] = rate;
		}

		for (int k = 1; k <= n; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					board[i][j] = max(board[i][j], board[i][k] * board[k][j]);

		bool flag = false;
		for (int i = 1; i <= n; i++)
			if (board[i][i] > 1.0)
			{
				flag = true;
				break;
			}
		printf("Case %d: ", t++);
		if (flag)
			printf("Yes\n");
		else
			printf("No\n");
	}
}