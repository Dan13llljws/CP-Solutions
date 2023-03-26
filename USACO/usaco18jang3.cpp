#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e6 + 6, mod = 1e9 + 7;
int n, m, k; ll dp[2][MM];
int main(){
	//freopen("spainting.in", "r", stdin); freopen("spainting.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++){
		dp[0][i] = ((dp[0][i - 1] - dp[0][max(i - k, 0)] + mod) * (m - 1) + dp[0][i - 1]) % mod;
		dp[1][i] = ((dp[0][max(i - k, 0)] + dp[1][i - 1]) * (m - 1) + dp[1][i - 1]) % mod;
		dp[i >= k][i] = (dp[i >= k][i] + m) % mod;
	}
	printf("%lld\n", (dp[1][n] - dp[1][n - 1] + mod) % mod);
}
