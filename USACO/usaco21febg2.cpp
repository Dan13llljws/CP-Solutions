#include <bits/stdc++.h>
using namespace std;
const int MM = 305;
int n, a[MM], dp[MM][MM];
int main(){
	scanf("%d", &n); memset(dp, 0x3f, sizeof dp);
	for (int i = 1; i <= n; i++) scanf("%d", a + i), dp[i][i] = 1;
	for (int len = 2; len <= n; len++)
		for (int l = 1, r = len; r <= n; l++, r++){
			if (a[l] == a[r]) dp[l][r] = min(dp[l][r - 1], dp[l + 1][r]);
			for (int i = l; i < r; i++) dp[l][r] = min(dp[l][r], dp[l][i] + dp[i + 1][r]);
		}
	printf("%d\n", dp[1][n]);
}
