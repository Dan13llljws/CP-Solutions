#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, MM = 1e4 + 5;
char str[MM]; int cur, n, d, dp[2][101][2];
int main(){
	scanf("%s %d", str + 1, &d); n = strlen(str + 1), dp[1][0][0] = 1;
	for (int i = 1; i <= n; i++, cur ^= 1){
		memset(dp[cur], 0, sizeof dp[cur]);
		for (int j = 0; j < d; j++)
			for (int dig = 0; dig < 10; dig++)
				if (dig < str[i] - '0') dp[cur][(j+dig)%d][1] = ((dp[cur][(j+dig)%d][1] + dp[cur ^ 1][j][1]) % mod + dp[cur ^ 1][j][0]) % mod;
				else if (dig == str[i] - '0'){
					dp[cur][(j+dig)%d][1] = (dp[cur][(j+dig)%d][1] + dp[cur ^ 1][j][1]) % mod;
					dp[cur][(j+dig)%d][0] = (dp[cur][(j+dig)%d][0] + dp[cur ^ 1][j][0]) % mod;
				} else dp[cur][(j+dig)%d][1] = (dp[cur][(j+dig)%d][1] + dp[cur ^ 1][j][1]) % mod;
	}
	printf("%d", (dp[cur ^ 1][0][0] + dp[cur ^ 1][0][1] - 1 + mod) % mod);
}
