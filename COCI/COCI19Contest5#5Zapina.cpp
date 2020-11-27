#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
int n; ll dp[355][355], fac[355], inv[355];
ll fpow(ll a, ll b){
	ll ret = 1;
	while(b){
		if (b & 1) ret = ret * a % mod;
		a = a * a % mod, b >>= 1;
	}
	return ret;
}
ll choose(int a, int b){return fac[a] * inv[b] % mod * inv[a - b] % mod;}
int main(){
	scanf("%d", &n);fac[0] = inv[0] = 1;
	for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod;
	inv[n] = fpow(fac[n], mod - 2);
	for (int i = n - 1; i; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
	dp[1][0] = 1;
	for (int i = 2; i <= n; i++) dp[1][i] = 1;
	for (int i = 1; i < n; i++)
		for (int j = 0; j <= n; j++)
			for (int k = 0; k <= n - j; k++)
				if (k != i + 1)
					dp[i + 1][j + k] = (dp[i + 1][j + k] + dp[i][j] * choose(j + k, k) % mod) % mod;
	printf("%lld\n", (fpow(n, n) - dp[n][n] + mod) % mod);
}

