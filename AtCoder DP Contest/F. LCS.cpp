#include <bits/stdc++.h>
using namespace std;
char a[3005], b[3005], ans[3005]; int n, m, p, dp[3005][3005];
int main(){
	scanf("%s %s", a + 1, b + 1); n = strlen(a + 1), m = strlen(b + 1);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
	p = dp[n][m];
	while(n && m){
		if (dp[n][m] == dp[n - 1][m]) n--;
		else if (dp[n][m] == dp[n][m - 1]) m--;
		else ans[--p] = a[n], n--, m--;
	}
	puts(ans);
}
	
