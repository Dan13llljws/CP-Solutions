#include <bits/stdc++.h>
const int mod = 1e9 + 7;
int n, c, dp[2][10005]; // number of ways for first i numbers to have c inversion
int main(){ // dp[i][c] = prefix sum of dp[i]
	scanf("%d%d", &n, &c); dp[0][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= c; j++)
			dp[i%2][j] = j ? ((dp[(i+1)%2][j] - (j >= i ? dp[(i+1)%2][j - i] : 0) + mod) % mod + dp[i%2][j - 1]) % mod : 1;
	printf("%d", dp[n%2][c] - dp[n%2][c + 1]);
	return 0;
}
