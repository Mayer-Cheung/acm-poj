#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 1e9;
int dp[105][105];
char s[105];

bool match(char a, char b)
{
	return (a == '(' && b == ')') || (a == '[' && b == ']');
}

void print(int i, int j)
{
	if (i > j)
		return;
	if (i == j)
	{
		if (s[i] == '(' || s[i] == ')')
			printf("()");
		if (s[i] == '[' || s[i] == ']')
			printf("[]");
		return;
	}
	int ans = dp[i][j];
	if (ans == dp[i + 1][j - 1] && match(s[i], s[j]))
	{
		printf("%c", s[i]);
		print(i + 1, j - 1);
		printf("%c", s[j]);
		return;
	}
	for (int k = i; k < j; k++)
	{
		if (ans == dp[i][k] + dp[k + 1][j])
		{
			print(i, k);
			print(k + 1, j);
			return;
		}
	}
}

int main()
{
	scanf("%s", s);
	int n = strlen(s);
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < n; i++)
		dp[i][i] = 1;
	for (int l = 1; l < n; l++)
	{
		for (int i = 0; i < n - l; i++)
		{
			int j = i + l;
			dp[i][j] = INF;
			if (match(s[i], s[j]))
				dp[i][j] = dp[i + 1][j - 1];
			for (int k = i; k < j; k++)
				dp[i][j] = min(dp[i][k] + dp[k + 1][j], dp[i][j]);
		}
	}
	print(0, n - 1);
	printf("\n");
}