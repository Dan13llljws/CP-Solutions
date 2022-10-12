#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n, s, t, dp[2005][2005];
int main(){
	scanf("%d%d%d", &n, &s, &t); dp[0][0] = 1;
	for (int i = 1; i < n; i++){
		for (int j = 0; j < i; j++){
			if (i != s && i != t){
				dp[i][j + 1] = (dp[i][j + 1] + dp[i - 1][j]) % mod;
				if (j) dp[i][j - 1] = (dp[i][j - 1] + 1LL * dp[i - 1][j] * j * (j - 1 + (i > s) + (i > t))) % mod;
			} else {
				dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
				if (j) dp[i][j - 1] = (dp[i][j - 1] + 1LL * dp[i - 1][j] * j) % mod;
			}
		}
	}
	printf("%d", dp[n - 1][0]);
}

