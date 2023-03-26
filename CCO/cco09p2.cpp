#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1e9 + 7, MM = 105;
int n, k, ans, dp[MM][MM][7][2]; char s[MM];
int main(){
	scanf("%d%d %s", &n, &k, s + 1); memset(dp, 0x3f, sizeof dp);
	for (int i = 1; i <= n; i++) dp[i][i][1][s[i] == 'G'] = 0;
	if (k == 1) for (int i = 1; i <= n; i++) dp[i][i][0][s[i] == 'G'] = 1;
	for (int len = 2; len <= n; len++)
		for (int l = 1, r = len; r <= n; l++, r++){
			for (int i = l; i < r; i++)
				for (int a = 0; a <= k; a++){
					for (int j = 0; j < 2; j++)
						dp[l][r][a][j] = min({dp[l][r][a][j], dp[l][i][a][j] + dp[i + 1][r][0][j ^ 1], dp[l][i][0][j ^ 1] + dp[i + 1][r][a][j]});
					for (int b = 0; b <= k; b++)
						for (int j = 0; j < 2; j++){
							int x = min(k, a + b);
							dp[l][r][x][j] = min(dp[l][r][x][j], dp[l][i][a][j] + dp[i + 1][r][b][j]);
						}
				}
			for (int j = 0; j < 2; j++)
				dp[l][r][0][j] = min(dp[l][r][0][j], dp[l][r][k][j] + 1);
		} ans = min(dp[1][n][0][0], dp[1][n][0][1]); printf("%d\n", ans < 1e9 ? ans : -1);
}

