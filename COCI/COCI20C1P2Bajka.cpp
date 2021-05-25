#include <bits/stdc++.h>
using namespace std;
int n, m, dp[305][305], ans = 1e9; char s[305], t[305];
int dfs(int i, int j){
	if (i == m) return 0;
	if (dp[i][j] != -1) return dp[i][j];
	int &ret = dp[i][j]; ret = 1e9;
	if (s[j - 1] == t[i + 1]) ret = min(ret, dfs(i + 1, j - 1) + 1);
	if (s[j + 1] == t[i + 1]) ret = min(ret, dfs(i + 1, j + 1) + 1);
	for (int k = 1; k <= n; k++) 
		if (s[k] == s[j]) ret = min(ret, dfs(i, k) + abs(k - j));
	return ret;
}
int main(){
	scanf("%d%d %s %s", &n, &m, s + 1, t + 1); memset(dp, -1, sizeof dp);
	for (int i = 1; i <= n; i++) 
		if (s[i] == t[1]) ans = min(ans, dfs(1, i));
	printf("%d\n", ans == 1e9 ? -1 : ans);
}
