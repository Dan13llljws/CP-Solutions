#include <bits/stdc++.h>
using namespace std;
int n, w, dp[300005], ans;
int main(){
	scanf("%d%d", &n, &w); memset(dp, 0x3f, sizeof dp); dp[0] = 0;
	for (int i = 0, t, v; i < n; i++){
		scanf("%d%d", &v, &t);
		for (int j = n * 1000; j >= t; j--)
			dp[j] = min(dp[j], dp[j - t] + v);
	}
	for (int i = 1; i <= n * 1000; i++) 
		if (dp[i] >= w) ans = max(ans, 1000 * i / dp[i]);
	printf("%d\n", ans);
}
