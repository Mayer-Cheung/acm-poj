#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int score['T' + 1]['T' + 1];
void initial()
{
    score['A']['A'] = 5;  
    score['C']['C'] = 5;  
    score['G']['G'] = 5;  
    score['T']['T'] = 5;  
    score['-']['-'] = - 5;  
    score['A']['C'] = score['C']['A'] = -1;  
    score['A']['G'] = score['G']['A'] = -2;  
    score['A']['T'] = score['T']['A'] = -1;  
    score['A']['-'] = score['-']['A'] = -3;  
    score['C']['G'] = score['G']['C'] = -3;  
    score['C']['T'] = score['T']['C'] = -2;  
    score['C']['-'] = score['-']['C'] = -4;  
    score['G']['T'] = score['T']['G'] = -2;  
    score['G']['-'] = score['-']['G'] = -2;  
    score['T']['-'] = score['-']['T'] = -1;
}
int max(int a, int b, int c)
{
	int k = b > c ? b : c;
	return a > k ? a : k;
}
int main()
{
	initial();
	int test;
	scanf("%d", &test);
	while (test--)
	{
		int len1, len2;
		scanf("%d", &len1);
		char* s1 = new char[len1 + 1];
		cin >> s1;
		scanf("%d", &len2);
		char* s2 = new char[len2 + 1];
		cin >> s2;

		int **dp = new int*[len1 + 1];
		dp[0] = new int[len2 + 1];
		dp[0][0] = 0;
		for (int i = 1; i <= len1; i++)
		{
			dp[i] = new int[len2 + 1];
			dp[i][0] = dp[i - 1][0] + score[s1[i - 1]]['-'];
		}
		for (int j = 1; j <= len2; j++)
		{
			dp[0][j] = dp[0][j - 1] + score[s2[j - 1]]['-'];
		}
		for (int i = 1; i <= len1; i++)
		{
			for (int j = 1; j <= len2; j++)
			{
				int t1 = dp[i - 1][j] + score[s1[i - 1]]['-'];
				int t2 = dp[i][j - 1] + score['-'][s2[j - 1]];
				int t3 = dp[i - 1][j - 1] + score[s1[i - 1]][s2[j - 1]];
				dp[i][j] = max(t1, t2, t3);
			}
		}
		printf("%d\n", dp[len1][len2]);
		delete[] dp;
	}
}