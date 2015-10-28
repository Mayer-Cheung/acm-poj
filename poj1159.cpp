#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[2][5005];
int main() {
    string s1, s2;
    int n;
    while (cin >> n) {
        cin >> s1;
        s2 = s1;
        reverse(s2.begin(), s2.end());
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i % 2][j] = dp[(i - 1) % 2][j] > dp[i % 2][j - 1] ? dp[(i - 1) % 2][j] : dp[i % 2][j - 1];
                if (s1[i - 1] == s2[j - 1]) {
                    int temp = dp[(i - 1) % 2][j - 1] + 1;
                    dp[i % 2][j] = dp[i % 2][j] > temp ? dp[i % 2][j] : temp;
                }
            }
        }
        cout << n - dp[n % 2][n] << "\n";
    }
    return 0;
}