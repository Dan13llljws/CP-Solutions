#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
int n; ll c[355][355], dp[355][355];
ll fpow(ll a, ll b){
	ll ret = 1;
	while(b){
		if (b & 1) ret = ret * a % mod;
		a = a * a % mod, b >>= 1;
	}
	return ret;
}
int main(){
	scanf("%d", &n);
	for (int i = 0; i <= n; i++){
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; j++)
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
	}
	dp[1][0] = 1;
	for (int i = 2; i <= n; i++) dp[1][i] = 1;
	for (int i = 1; i < n; i++)
		for (int j = 0; j <= n; j++)
			for (int k = 0; k <= n - j; k++)
				if (k != i + 1)
					dp[i + 1][j + k] = (dp[i + 1][j + k] + dp[i][j] * c[j + k][k] % mod) % mod;
	printf("%lld\n", (fpow(n, n) - dp[n][n] + mod) % mod);
}

