#include <bits/stdc++.h>
const int mod = 1e9 + 7;
char str[3005]; int n, cur, dp[2][3005];
int main(){
	scanf("%d %s", &n, str + 2); dp[1][1] = 1;
	for (int i = 2; i <= n; i++, cur ^= 1)
		for (int j = 1; j <= i; j++)
			if (str[i] == '<') dp[cur][j] = (dp[cur][j - 1] + dp[cur ^ 1][j - 1]) % mod;
			else dp[cur][j] = ((dp[cur][j - 1] + dp[cur ^ 1][i - 1]) % mod - dp[cur ^ 1][j - 1] + mod) % mod;
	printf("%d", dp[cur ^ 1][n]);
}
