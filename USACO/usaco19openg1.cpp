#include <bits/stdc++.h>
using namespace std;
const int MM = 405;
int n, k, a[MM], psa[MM], dp[MM][MM];
int main(){
	//freopen("snakes.in", "r", stdin); freopen("snakes.out", "w", stdout);
	scanf("%d%d", &n, &k); k++; memset(dp, 0x3f, sizeof dp); dp[0][0] = 0;
	for (int i = 1; i <= n; i++) scanf("%d", a + i), psa[i] = a[i] + psa[i - 1];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= k; j++){
			int mx = a[i];
			for (int i1 = i; i1; i1--){
				mx = max(mx, a[i1]);
				dp[i][j] = min(dp[i][j], dp[i1 - 1][j - 1] + mx * (i - i1 + 1) - psa[i] + psa[i1 - 1]);
			}
		}
	printf("%d\n", dp[n][k]);
}
