#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int dp[205][2052];
char A[205], B[205], C[205];

int main()
{
	int test;
	scanf("%d", &test);
	for (int i = 1; i <= test; i++)
	{
		scanf("%s %s %s", A + 1, B + 1, C + 1);		
		printf("Data set %d: ", i);
		int lena = strlen(A + 1);
		int lenb = strlen(B + 1);
		int lenc = strlen(C + 1);
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		for (int i  = 0; i <= lena; i++)
		{
			for (int j = 0; j <= lenb; j++)
			{
				if (i > 0 && A[i] == C[i + j] && dp[i - 1][j] == 1)
					dp[i][j] = 1;
				if (j > 0 && B[j] == C[i + j] && dp[i][j - 1] == 1)
					dp[i][j] = 1;
			}
		}
		if (dp[lena][lenb] == 1)
			printf("yes\n");
		else
			printf("no\n");
	}
}