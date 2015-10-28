#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
int dp[505][505];
int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		memset(dp, 0, sizeof(dp));
		int len1 = str1.length(), len2 = str2.length();
		for (int i = 0; i <= len2; i++)
			dp[0][i] = 0;
		for (int i = 0; i <= len1; i++)
			dp[i][0] = 0;
		for (int i = 1; i <= len1; i++)
		{
			for (int j = 1; j <= len2; j++)
			{
				if (str1[i - 1] == str2[j - 1])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
		printf("%d\n", dp[len1][len2]);
	}
}